#include "dynamics_modules.h"
#include "mat_ops.h"
#include "quat_ops.h"
#include "vec_ops.h"
#include "math.h"



/* mat_ops.h for matrix operations
 * quat_ops.h for quaternion operations
 * vec_ops.h for vector operation
*/

/*
 * Function: rk4_wbi
 * --------------------
 *  4th Order Runge Kutta Integrator which calculates the angular velocity of body with
 *  respect to inertial frame.
 *  Takes I (Inertia Matrix I, Inverse of Inertia Matrix Iinv ,Control Torque Tc, Disturbance Torque Td,
             Previous w_bi, step size h for runge kutta integrator)
 *  returns: Angular Velocity  w_bi(VECTOR)
 */
VECTOR rk4_wbi(MATRIX I,MATRIX Iinv,VECTOR Tc,VECTOR Td,VECTOR w_bi,double h)
{
    VECTOR a,b,c,d,temp;
    int i;
    a=funcEval_dwdt(I,Iinv,Tc,Td,w_bi);
    for(i=0; i<3; i++)
        a.vec[i]=a.vec[i]*h;

    for(i=0; i<3; i++)
        temp.vec[i]=w_bi.vec[i]+a.vec[i]/2;

    b=funcEval_dwdt(I,Iinv,Tc,Td,temp);
    for(i=0; i<3; i++)
        b.vec[i]=b.vec[i]*h;

    for(i=0; i<3; i++)
        temp.vec[i]=w_bi.vec[i]+b.vec[i]/2;

    c=funcEval_dwdt(I,Iinv,Tc,Td,temp);
    for(i=0; i<3; i++)
        c.vec[i]=c.vec[i]*h;

    for(i=0; i<3; i++)
        temp.vec[i]=w_bi.vec[i]+c.vec[i];

    d=funcEval_dwdt(I,Iinv,Tc,Td,temp);
    for(i=0; i<3; i++)
        d.vec[i]=d.vec[i]*h;

    for(i=0; i<3; i++)
        w_bi.vec[i]=w_bi.vec[i]+((a.vec[i]/6)+(b.vec[i]/3)+(c.vec[i]/3)+(d.vec[i]/6));
    return w_bi;
}
/*
 * Function:   rk4_qdot
 * --------------------
 *  4th order runge kutta integrator which calculates the quaternion of body with respect
 *  to inertial frame.
 *
 *  returns: q (QUATERNION)
 */
QUATERNION rk4_qdot(double h,QUATERNION q,VECTOR wn)
{
    QUATERNION k1,k2,k3,k4,t,w;
    int i;
    w=vect2quat(wn);
    k1=qb2i(q,w,h/2);
    for(i=0; i<4; i++) t.quat[i]=q.quat[i]+h*k1.quat[i]/2;
    k2=qb2i(t,w,h/2);
    for(i=0; i<4; i++) t.quat[i]=q.quat[i]+h*k2.quat[i]/2;
    k3=qb2i(t,w,h/2);
    for(i=0; i<4; i++) t.quat[i]=q.quat[i]+h*k3.quat[i];
    k4=qb2i(t,w,h);
    for(i=0; i<4; i++) q.quat[i]=q.quat[i] + h/6*(k1.quat[i]+2*k2.quat[i]+2*k3.quat[i]+k4.quat[i]);
    return q;
}
/*
 * Function:   rk4_ri
 * --------------------
 *  4th order runge kutta integrator which calculate the reference quaternion with respect to the
 *  inertial frame.
 *  returns:
 */
QUATERNION rk4_qri(double h,QUATERNION q,VECTOR wn)
{
    QUATERNION k1,k2,k3,k4,t,w;
    int i;
    w=vect2quat(wn);
    k1=qb2i(q,w,h/2);
    for(i=0; i<4; i++) t.quat[i]=q.quat[i]+h*k1.quat[i]/2;
    k2=qb2i(t,w,h/2);
    for(i=0; i<4; i++) t.quat[i]=q.quat[i]+h*k2.quat[i]/2;
    k3=qb2i(t,w,h/2);
    for(i=0; i<4; i++) t.quat[i]=q.quat[i]+h*k3.quat[i];
    k4=qb2i(t,w,h);
    for(i=0; i<4; i++) q.quat[i]=q.quat[i] + h/6*(k1.quat[i]+2*k2.quat[i]+2*k3.quat[i]+k4.quat[i]);
    return q;
}
/*
 * Function:   qb2i
 * --------------------
 *  Called by rk4_dot to evaluate the equation dq/dt=1/2(q*w) where w is [0 velocity vector]
 *  returns: quaternion q
 */
QUATERNION qb2i(QUATERNION y,QUATERNION w,double x)
{
    int i;
    QUATERNION q;
    q=quatmultiply(y,w);
    for(i=0; i<4; i++)
    {
        q.quat[i]=q.quat[i]/2;
    }
    return q;
}
/*
 * Function:   funcEval_dwdt
 * --------------------
 *  Called by rk4_wbi to evaluate the differential equation dw/dt= (1/I)( Tc+Td -w*(Ixw))
 *
 *  returns: wbi Vector
 */
VECTOR funcEval_dwdt(MATRIX I,MATRIX Idash,VECTOR Tc,VECTOR Td,VECTOR w)
{
    int i,j;
    VECTOR iXw,wbi,d,T;
    for(i=0; i<3; i++)
    {
        iXw.vec[i]=0;
        for(j=0; j<3; j++)
            iXw.vec[i]+=I.mat[i][j]*w.vec[j];
    }
    d=cross_product(w,iXw);
    for(i=0; i<3; i++)
        T.vec[i]=Tc.vec[i]+Td.vec[i]-d.vec[i];

    for(i=0; i<3; i++)
    {
        wbi.vec[i]=0;
        for(j=0; j<3; j++)
            wbi.vec[i]+=Idash.mat[i][j]*T.vec[j];
    }
    return wbi;
}
/*
 * Function: calc_Tbr
 * --------------------
 *  Calculates tranformation matrix Tbr
 *  returns: temp (MATRIX)
 */
MATRIX calc_Tbr(MATRIX x, MATRIX y, MATRIX z)
{
    MATRIX temp;
    temp=matzero();
    temp=mat_mul(x,y);
    temp=mat_mul(temp,z);
    return temp;
}
/*
 * Function:  calc_wbi
 * --------------------
 *   Calculates initial w_bi using w0 and w_br and transformation matrix Tbr
 *   returns: w_bi (VECTOR)
 */
VECTOR calc_wbi(VECTOR w_bi,VECTOR w_br,VECTOR w0,MATRIX Tbr)
{
    MATRIX w_bi_m;
    int i;
    w_bi_m.row=3;
    w_bi_m.col=1;
    w_bi=veczero();
    for(i=0; i<3; i++)
        w_bi_m.mat[i][0]=w0.vec[i];
    w_bi_m=mat_mul(Tbr,w_bi_m);
    for(i=0; i<3; i++)
        w_bi.vec[i]=w_br.vec[i]+w_bi_m.mat[i][0];
    return w_bi;
}

