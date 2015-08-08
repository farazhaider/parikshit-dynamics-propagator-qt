#include "dashboard.h"
#include "math.h"
#include <QVector>
#include <QDebug>
Dashboard::Dashboard(QObject *parent) :
    QObject(parent)
{
}



VECTOR quat2angle(QUATERNION q)
{
    double sqw = q.quat[0]*q.quat[0];
    double sqx = q.quat[1]*q.quat[1];
    double sqy = q.quat[2]*q.quat[2];
    double sqz = q.quat[3]*q.quat[3];
    double unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
    double test = q.quat[1]*q.quat[2] + q.quat[3]*q.quat[0];
    VECTOR v;
    double PI = 3.1415926;
    if (test > 0.499*unit)   // singularity at north pole
    {
        v.vec[1]= 2 * atan2(q.quat[1],q.quat[0]);
        v.vec[2]= PI/2;
        v.vec[0]= 0;
        return v;
    }
    if (test < -0.499*unit)   // singularity at south pole
    {
        v.vec[1] = -2 * atan2(q.quat[1],q.quat[0]);
        v.vec[2] = -PI/2;
        v.vec[0] = 0;
        return v;
    }
    v.vec[1] = atan2(2*q.quat[1]*q.quat[0]-2*q.quat[1]*q.quat[3] , sqx - sqy - sqz + sqw);
    v.vec[2] = asin(2*test/unit);
    v.vec[0] = atan2(2*q.quat[1]*q.quat[0]-2*q.quat[2]*q.quat[3] , -sqx + sqy - sqz + sqw);
    return v;
}


adcsElements& Dashboard::adcs_engine(double step,double final_time,double r[],double v[],VECTOR w_br,VECTOR w_bi,VECTOR Td,VECTOR e,adcsElements &element)
{
   /*******************************************Declarations*****************************************/
    double w_bi_mag,w_c,zeta;
    double Kpx,Kpy,Kpz,Kdx,Kdy,Kdz,Kix,Kiy,Kiz,Tcx,Tcy,Tcz;
    VECTOR w0,w_err;
    VECTOR Tc;
    MATRIX Rx,Ry,Rz,Tbr;
    VECTOR q_err_angle,q_dot_angle;
    MATRIX I,Idash;
    QUATERNION q0, q_br, q_bi, q_dot, q_w0, q_ref, q_err,q_err_int, q_err_dot, q_w_bi, q_err_dot_1, q_err_dot_2;
    double vr,h[3],H,N[3],angleOfIncidence,RAAN,RAAND,ex[3],E,AGP,AGPD,MA,MAD,sa,T,n,Eo,root_factor;
    double T1,Tf,np,Tnrp,Mnrp,Enrp,Fe,dFe,ratio,TAnrp,rTAnrp[3],p,vTAnrp[3],dRAAN,omega,dagp,argumentOfPerigee,rnew[3],vnew[3];
    long int nrp;
    double temp[3];
    int i;
    double time;
    /*********************************************OP_CONDITIONS***********************************/

    temp[0]=0;
    temp[1]=0;
    temp[2]=1;

    dot_product1(v, r, &vr);
    vr=vr/norm(r);
    cross_product1(r, v, h);
    H=norm(h);
    angleOfIncidence=acos((h[2]/H));
    cross_product1(temp, h, N);
    RAAN=acos((N[0]/norm(N)));
    RAAND=RAAN*180/pi;
    if (N[1]>=0)
        RAAND=RAAND;
    else
        RAAND=360-RAAND;

    RAAN=RAAND*pi/180;
    cross_product1(v,h,ex);
    int kx;
    for(kx=0; kx<3; kx++) ex[kx]=ex[kx]/mu-r[kx]/norm(r);
    E=norm(ex);
    dot_product1(N, ex, &AGP);
    AGP=acos(AGP/(norm(N)*E));
    AGPD=AGP*180/pi;
    if (ex[2]>=0)
        AGPD=AGPD;
    else
        AGPD=360-AGPD;
    AGP=AGPD*pi/180;
    dot_product1(ex,r,&MA);
    MA=acos(MA/(norm(ex)*norm(r)));
    MAD=MA*180/pi;
    if (vr>=0)
        MAD=MAD;
    else
        MAD=360-MAD;
    MA=MAD*pi/180;

    sa=(pow(H,2)/mu)*(1/(1-pow(E,2)));
    T=(2*pi/sqrt(mu))*pow(sa,1.5);
    n=2*pi/(T);



    double initialJulianDate;
    double gst;

    initialJulianDate=jdut(2013,1,17,23,25,30);
    double currentJulianDate;



    /********************************************************DP_CONDITIONS*****************************************/

    /* opening file stream to write values  of calculated parameters to their respective files for plotting purposes*/


    /* assigning initial values to angular velocities */



    /* w0 a constant */
    w0=veczero();
    w0.vec[1]=-0.001036290469464;

    /* yaw pitch roll  i.e psi theta phi */

    /* Calculating q_bi from q_br */
    q0=qzero();
    q_br=angle2quat(e.vec[0],e.vec[1],e.vec[2]);
    q_bi=quatmultiply(q_br,q0);
    q_w0=vect2quat(w0);

    /* Moment Of Inertia Matrix */
    I=matzero();
    I.mat[0][0]=2.33869e-3;
    I.mat[1][1]=6.6726503e-3;
    I.mat[2][2]=5.938327e-3;
    Idash=inverse(I);

    /* Control and disturbance torque inital values */
    Tc=veczero();

    /* Calculating w_bi from rotation matrix */
    Rx=matzero();
    Ry=matzero();
    Rz=matzero();
    Rx.mat[0][0]=1;
    Rx.mat[1][1]=cos(e.vec[0]);
    Rx.mat[1][2]=-sin(e.vec[0]);
    Rx.mat[2][1]=sin(e.vec[0]);
    Rx.mat[2][2]=cos(e.vec[0]);
    Ry.mat[0][0]=cos(e.vec[1]);
    Ry.mat[0][2]=sin(e.vec[1]);
    Ry.mat[1][1]=1;
    Ry.mat[2][0]=-sin(e.vec[1]);
    Ry.mat[2][2]=cos(e.vec[1]);
    Rz.mat[0][0]=cos(e.vec[2]);
    Rz.mat[0][1]=-sin(e.vec[2]);
    Rz.mat[1][0]=sin(e.vec[2]);
    Rz.mat[1][1]=cos(e.vec[2]);
    Rz.mat[2][2]=1;
    Tbr=calc_Tbr(Rx,Ry,Rz);
    w_bi=calc_wbi(w_bi,w_br,w0,Tbr);


    /* Calculating Control Values  and w_c is bandwidth */
    /* calculating control constants make it in a function*/
    /* Zeta is damping coefficient in control systems and w_c is the bandwidth */

    zeta=0.7;
    root_factor=0.001;
    w_c=2*fabs(w0.vec[1]);

        Kpx = I.mat[0][0]*(2*root_factor*zeta*zeta +1)*pow(w_c,2);
        Kpy = I.mat[1][1]*(2*root_factor*zeta*zeta +1)*pow(w_c,2);
        Kpz = I.mat[2][2]*(2*root_factor*zeta*zeta +1)*pow(w_c,2);
        Kdx = I.mat[0][0]*zeta*w_c*(root_factor+2);
        Kdy = I.mat[1][1]*zeta*w_c*(root_factor+2);
        Kdz = I.mat[2][2]*zeta*w_c*(root_factor+2);

        Kix=I.mat[0][0]*pow(w_c,2)*root_factor*zeta;
        Kiy=I.mat[1][1]*pow(w_c,2)*root_factor*zeta;
        Kiz=I.mat[2][2]*pow(w_c,2)*root_factor*zeta;



    q_dot=q_bi;
    q_ref=qzero();
    q_w0=vect2quat(w0);
    q_err_int=qzero();

    w_bi.vec[0]=0.1869693;
    w_bi.vec[1]=0.1451308;
    w_bi.vec[2]=0.0616488;

//    w_bi.vec[0]=0.9574;
//    w_bi.vec[1]=0.4158;
//    w_bi.vec[2]=-0.2407;


    /* Aligning the output files for proper plotting */




    for(time=0;time<=final_time;time+=step)
    {
        /******************OP Iteration***************************************************/
        VECTOR v,mag;
        currentJulianDate=initialJulianDate+(time/86400.0);
        gst=jdut2gmst(currentJulianDate);
        gst=gst*pi/180.0;
        Eo=2*(atan(sqrt((1-E)/(1+E))*tan(MA/2)));
        T1=(Eo-E*sin(Eo))/n;
        Tf=T1+time;
        np=Tf/T;
        nrp=floor(np);
        Tnrp=(np-nrp)*T;
        Mnrp=n*Tnrp;
        if (Mnrp<=pi)
            Enrp=Mnrp+E/2;
        else
            Enrp=Mnrp-E/2;
        Fe=Enrp-E*sin(Enrp)-Mnrp;
        dFe=1-E*cos(Enrp);
        ratio=Fe/dFe;
        double term=1e-8;
        while (fabs(ratio) > term)
        {
            Enrp=Enrp-ratio;
            Fe=Enrp-E*sin(Enrp)-Mnrp;
            dFe=1-E*cos(Enrp);
            ratio=Fe/dFe;
        }
        TAnrp=2*(atan(sqrt((1+E)/(1-E))*tan(Enrp/2)));
        rTAnrp[0]=((pow)(H,2)/mu)*(1/(1+E*cos(TAnrp)))*cos(TAnrp);
        rTAnrp[1]=((pow)(H,2)/mu)*(1/(1+E*cos(TAnrp)))*sin(TAnrp);
        rTAnrp[2]=0;
        p=pow(H,2)/mu;
        vTAnrp[0]=sqrt(mu/p)*(-sin(TAnrp));
        vTAnrp[1]=sqrt(mu/p)*(E+cos(TAnrp));
        vTAnrp[2]=0;
        dRAAN=(J2*pow(re,2)*n*cos(angleOfIncidence))/(pow(p,2));
        dRAAN=dRAAN * (-1.5);
        omega=RAAN+dRAAN*time;
        dagp=(2-(2.5)*pow((sin(angleOfIncidence)),2))/pow(p,2);
        dagp=dagp*(J2*pow(re,2)*n);
        dagp=dagp * 1.5;
        argumentOfPerigee=AGP+dagp*time;


        rnew[0]=(cos(omega)*cos(argumentOfPerigee)-sin(omega)*sin(argumentOfPerigee)*cos(angleOfIncidence))*rTAnrp[0]  +   (-cos(omega)*sin(argumentOfPerigee)-sin(omega)*cos(argumentOfPerigee)*cos(angleOfIncidence))*rTAnrp[1]  +  sin(omega)*sin(angleOfIncidence)*rTAnrp[2];
        rnew[1]=(sin(omega)*cos(argumentOfPerigee)+cos(omega)*sin(argumentOfPerigee)*cos(angleOfIncidence))*rTAnrp[0] + (-sin(omega)*sin(argumentOfPerigee)+cos(omega)*cos(argumentOfPerigee)*cos(angleOfIncidence))*rTAnrp[1]  +(-cos(omega)*sin(angleOfIncidence))*rTAnrp[2];
        rnew[2]= sin(argumentOfPerigee)*sin(angleOfIncidence)*rTAnrp[0] + cos(argumentOfPerigee)*sin(angleOfIncidence)*rTAnrp[1] + cos(angleOfIncidence)*rTAnrp[2];
        vnew[0]=(cos(omega)*cos(argumentOfPerigee)-sin(omega)*sin(argumentOfPerigee)*cos(angleOfIncidence))*vTAnrp[0]  +   (-cos(omega)*sin(argumentOfPerigee)-sin(omega)*cos(argumentOfPerigee)*cos(angleOfIncidence))*vTAnrp[1]  +  sin(omega)*sin(angleOfIncidence)*vTAnrp[2];
        vnew[1]=(sin(omega)*cos(argumentOfPerigee)+cos(omega)*sin(argumentOfPerigee)*cos(angleOfIncidence))*vTAnrp[0] + (-sin(omega)*sin(argumentOfPerigee)+cos(omega)*cos(argumentOfPerigee)*cos(angleOfIncidence))*vTAnrp[1]  +(-cos(omega)*sin(angleOfIncidence))*vTAnrp[2];
        vnew[2]= sin(argumentOfPerigee)*sin(angleOfIncidence)*vTAnrp[0] + cos(argumentOfPerigee)*sin(angleOfIncidence)*vTAnrp[1] + cos(angleOfIncidence)*vTAnrp[2];


        MATRIX ecef=eci_ecef(rnew,gst);
        v=ecef_lla(ecef);


        mag=igrf(v.vec[2],v.vec[0],v.vec[1],2013,gh);
        MATRIX trans;
        trans=eci_orbit(argumentOfPerigee,TAnrp,omega,angleOfIncidence);

        MATRIX mag_eci;
        mag_eci.row=3;
        mag_eci.col=1;

        for(i=0; i<3; i++) mag_eci.mat[i][0]=mag.vec[i];
        // Magnetic field in orbit frame
        MATRIX mag_orb;
        mag_orb=mat_mul(trans,mag_eci);




        /****************************************DP***********************************************************************/



        /*Runge Kutta 4th order integrator to calculate value of w_bi at each step */
        w_bi=rk4_wbi(I,Idash,Tc,Td,w_bi,step);

        /* Runge Kutta 4th order integrator to calculate value of q_dot at each step */
        q_dot=rk4_qdot(step,q_dot,w_bi);
        /* Runge Kutta 4th order integrator to calculate value of q_ri at each step */
        q_ref=rk4_qri(step,q_ref,w0);
        w_bi_mag=vec_mag(w_bi);
        q_w_bi=vect2quat(w_bi);
        q_err=quatmultiply(quatinv(q_dot),q_ref);
        q_err_dot_1=quatmultiply(q_err,q_w0);
        q_err_dot_2=quatmultiply(q_w_bi,q_err);
        for(i=0; i<4; i++) q_err_dot.quat[i]=0.5*(q_err_dot_1.quat[i]-q_err_dot_2.quat[i]);
        for(i=0; i<3; i++) w_err.vec[i]=w0.vec[i]-w_bi.vec[i];

        QUATERNION tempq;
        for(i=0;i<4;i++) tempq.quat[i]=q_err.quat[i]*step;
        q_err_int = quat_add(q_err_int,tempq);

        /* Determining control torque based on error from reference */
//        Tcx = Kpx*q_err.quat[1] +(Kdx)*w_err.vec[0] + Kix*q_err_int.quat[1];
//        Tcy = Kpy*q_err.quat[2] +(Kdy)*w_err.vec[1] + Kiy*q_err_int.quat[2];
//        Tcz = Kpz*q_err.quat[3] +(Kdz)*w_err.vec[2] + Kiz*q_err_int.quat[3];


        Tcx = Kpx*q_err.quat[1]*q_err.quat[0] +(Kdx)*w_err.vec[0];
        Tcy = Kpy*q_err.quat[2]*q_err.quat[0] +(Kdy)*w_err.vec[1];
        Tcz = Kpz*q_err.quat[3]*q_err.quat[0] +(Kdz)*w_err.vec[2];


        Tc.vec[0]=Tcx;
        Tc.vec[1]=Tcy;
        Tc.vec[2]=Tcz;

       q_err_angle=quat2angle(q_err);
       q_dot_angle=quat2angle(q_dot);

       element.q_dot_angle_x<< q_dot_angle.vec[0];
       element.q_dot_angle_y<< q_dot_angle.vec[1];
       element.q_dot_angle_z<< q_dot_angle.vec[2];

       element.q_err_angle_x<< q_err_angle.vec[0];
       element.q_err_angle_y<< q_err_angle.vec[1];
       element.q_err_angle_z<< q_err_angle.vec[2];


       element.w_bi_x  << w_bi.vec[0] * 180/pi;
       element.w_bi_y  << w_bi.vec[1] * 180/pi;
       element.w_bi_z  << w_bi.vec[2] * 180/pi;

       element.w_err_x << w_err.vec[0] * 180/pi;
       element.w_err_y << w_err.vec[1] * 180/pi;
       element.w_err_z << w_err.vec[2] * 180/pi;

      element.q_bi_a << q_dot.quat[0];
      element.q_bi_x << q_dot.quat[1];
      element.q_bi_y << q_dot.quat[2];
      element.q_bi_z << q_dot.quat[3];

      element.q_err_a << q_err.quat[0];
      element.q_err_x << q_err.quat[1];
      element.q_err_y << q_err.quat[2];
      element.q_err_z << q_err.quat[3];

      element.q_ref_a << q_ref.quat[0];
      element.q_ref_x << q_ref.quat[1];
      element.q_ref_y << q_ref.quat[2];
      element.q_ref_z << q_ref.quat[3];


      element.magnetic_field_x << mag_orb.mat[0][0];
      element.magnetic_field_y << mag_orb.mat[1][0];
      element.magnetic_field_z << mag_orb.mat[2][0];

      element.velocity_x << vnew[0];
      element.velocity_y << vnew[1];
      element.velocity_z << vnew[2];

      element.radius_x << rnew[0];
      element.radius_y << rnew[1];
      element.radius_z << rnew[2];

      element.time << time;


    }
    return element;
}
