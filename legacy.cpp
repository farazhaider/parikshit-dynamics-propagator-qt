#include "legacy.h"
#include "math.h"
void dot_product1(double v[],double r[],double *vr)
{
    *vr=0;
    int i=0;
    for(i=0; i<3; i++)
        (*vr)+=v[i]*r[i];
}

void cross_product1(double r[], double v[],double *h)
{
    h[0]= r[1]*v[2]-r[2]*v[1];
    h[1]= r[2] * v[0] - r[0]*v[2];
    h[2]= r[0]*v[1] - r[1]*v[0];
}

double norm(double r[])
{
    double a;
    a=0;
    a=pow(r[0],2);
    a+=pow(r[1],2);
    a+=pow(r[2],2);
    a=sqrt(a);
    return a;
}
