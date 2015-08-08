#include "ephimeredes.h"
#include "math.h"

// JDUT working fine
double jdut(int Y,int M,int D,int HR,int MN,int SEC)
{
    long A,B,C,E;
    double JD;
    if(M==1 || M==2)
    {
        Y=Y-1;
        M=M+12;
    }
    A=(int)(Y/100.0);
    B=2-A+(int)A/4;
    if(Y<0)
    {
        C=(int)(365.25*Y-0.75);
    }
    C=(int)(365.25*Y);
    E=(int)(30.6001*(M+1));
    JD=B+C+D+E+1720994.5;
    JD=JD+ (HR)/24.0 + MN/1440.0 + SEC/86400.0;
    return JD;
}


double jdut2gmst(double JD)
{
    double H;
    double diff=fabs(floor(JD)-JD);
    if(diff<=0.5)
    {
        H=(diff+0.5)*24;
    }
    else
    {
        H=(diff-0.5)*24;
    }
    double JD0=JD-H/24;
    double D=JD-2451545.0;
    double D0=JD0-2451545.0;
    double T=D/36525;
    double GMST= 6.697374558 + 0.06570982441908*D0 + 1.00273790935*H + 0.000026*T*T;
    long quotient=(long)GMST/24;
    double GMST_0_24=fabs(24*quotient-GMST)*15.0;
    return GMST_0_24;
}

