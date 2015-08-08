#include "frame_conversions.h"
#include "math.h"
#include "astro_constants.h"

VECTOR ecef_lla(MATRIX ecef)
{

    VECTOR v;
    v=veczero();
    v.vec[1]=atan2(ecef.mat[1][0],ecef.mat[0][0])*(180/pi);

    double a = 6.378137e3; // radius
    double e = 8.1819190842622e-2;  // eccentricity
    double asq = pow(a,2);
    double esq = pow(e,2);

    double b = sqrt( asq * (1-esq) );
    double bsq = pow(b,2);
    double ep = sqrt( (asq - bsq)/bsq);
    double p = sqrt( pow(ecef.mat[0][0],2) + pow(ecef.mat[1][0],2) );
    double th = atan2(a*ecef.mat[2][0], b*p);

    v.vec[0] = atan2( (ecef.mat[2][0] + pow(ep,2)*b*pow(sin(th),3) ), (p - esq*a*pow(cos(th),3)) )*(180/pi);
    double N = a/( sqrt(1-esq*pow(sin(v.vec[0]),2)) );
    v.vec[2] = p / cos(v.vec[0]*(pi/180)) - N;
    return v;
}

MATRIX eci_orbit(double agp,double  TAnrp, double ohm, double i)
{
    MATRIX m;
    m.row=m.col=3;
    m.mat[0][0]=-sin(agp+TAnrp)*cos(ohm)+-cos(i)*sin(ohm)*cos(agp+TAnrp);
    m.mat[0][1]=-sin(agp+TAnrp)*sin(ohm)+cos(i)*cos(ohm)*cos(agp+TAnrp);
    m.mat[0][2]=cos(agp+TAnrp)*sin(i);
    m.mat[1][0]=-sin(i)*sin(ohm);
    m.mat[1][1]=sin(i)*cos(ohm);
    m.mat[1][2]=-cos(i);
    m.mat[2][0]=-cos(agp+TAnrp)*cos(ohm)+cos(i)*sin(ohm)*sin(agp+TAnrp);
    m.mat[2][1]=-cos(agp+TAnrp)*sin(ohm)-cos(i)*cos(ohm)*sin(agp+TAnrp);
    m.mat[2][2]=-sin(agp+TAnrp)*sin(i);
    return m;
}


MATRIX eci_ecef(double rnew[],double gst)
{
    MATRIX eci_ecef;
    eci_ecef.row=3;
    eci_ecef.col=3;

    eci_ecef.mat[0][0]=cos(gst);
    eci_ecef.mat[0][1]=sin(gst);
    eci_ecef.mat[0][2]=0;

    eci_ecef.mat[1][0]=-sin(gst);
    eci_ecef.mat[1][1]=cos(gst);
    eci_ecef.mat[1][2]=0;

    eci_ecef.mat[2][0]=0;
    eci_ecef.mat[2][1]=0;
    eci_ecef.mat[2][2]=1;

    MATRIX eci;
    eci.row=3;
    eci.col=1;

    eci.mat[0][0]=rnew[0];
    eci.mat[1][0]=rnew[1];
    eci.mat[2][0]=rnew[2];

    MATRIX ecef;
    ecef=mat_mul(eci_ecef,eci);
    return ecef;
}
