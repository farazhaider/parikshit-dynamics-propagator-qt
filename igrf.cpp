#include "igrf.h"
#include "math.h"
#include "stdlib.h"

VECTOR igrf(double alt,double lat,double elong,int fyears,float gh[])
{
    // Required Variables
    VECTOR magnetic_field;
    double x,y,z,colat,t,tc,r,one,two,three,ct,st,cd,sd,a2,b2;
    double rho,ratio,rr;
    int k,m,j,gn,itype,lm,isv,nc,i,ll,l,kmx,nmx,n,fn,fm,gmm;
    double *cl,*sl,*p,*q;
    int loop=0;
    j=0;
    isv=0;
    itype=1;
    colat=90-lat;
    cl=(double*)calloc(sizeof(double),13);
    sl=(double*)calloc(sizeof(double),13);
    x=0;
    y=0;
    z=0;
    t=fyears-2010;
    tc=1;

    if(isv==1)
    {
        t=1;
        tc=0;
    }
    ll=2865;
    nmx=13;
    nc=nmx*(nmx+2);
    kmx=105;
    r=alt;
    one=colat*0.017453292;
    ct=cos(one);
    st=sin(one);
    one=elong*0.017453292;
    cl[0]=cos(one);
    sl[0]=sin(one);
    cd=1.0;
    sd=0.0;
    l=1;
    m=1;
    n=0;

    if(itype==1)
    {
        a2=40680631.6;
        b2=40408296.0;
        one=a2*st*st;
        two=b2*ct*ct;
        three=one+two;
        rho=sqrt(three);
        r=sqrt(alt*(alt+2.0*rho) + (a2*one + b2*two)/three);
        cd=(alt+rho)/r;
        sd=(a2-b2)/rho*ct*st/r;
        one=ct;
        ct=ct*cd- st*sd;
        st=st*cd + one*sd;
    }
    ratio=6371.2/r;
    rr=ratio*ratio;
    p=(double*)calloc(sizeof(double),105);
    q=(double*)calloc(sizeof(double),105);
    for(loop=0; loop<105; loop++)
    {
        p[loop]=1;
        q[loop]=1;
    }
    p[0]=1.0;
    p[2]=st;
    q[0]=0.0;
    q[2]=ct;
    for(k=2; k<=kmx; k++)
    {
        if(n<m)
        {
            m=0;
            n=n+1;
            rr=rr*ratio;
            fn=n;
            gn=n-1;
        }
        fm=m;
        if(m==n && k!=3)
        {
            one=sqrt(1.0-0.5/fm);
            j=k-n-1;
            p[k-1]=one*st*p[j-1];
            q[k-1]=one*(st*q[j-1]+ct*p[j-1]);
            cl[m-1]=cl[m-2]*cl[0] - sl[m-2]*sl[0];
            sl[m-1]=sl[m-2]*cl[0] + cl[m-2]*sl[0];
        }
        if(m!=n && k!=3)
        {
            fn=n;
            gn=n-1;
            gmm=m*m;
            one=sqrt(fn*fn-gmm);
            two=sqrt(gn*gn-gmm)/one;
            three=(fn+gn)/one;
            i=k-n;
            j=i-n+1;
            p[k-1]=three*ct*p[i-1]-two*p[j-1];
            q[k-1]=three*(ct*q[i-1]-st*p[i-1])-two*q[j-1];
        }
        lm=ll+l;
        one=(tc*gh[lm-1] + t*gh[lm+nc-1])*rr;

        if(m!=0)
        {
            fn=n;
            two=(tc*gh[lm] + t*gh[lm+nc]) *rr;
            three=one*cl[m-1] + two*sl[m-1];
            x=x+three*q[k-1];
            z=z-(fn +1.0)*three*p[k-1];
            if(st!=0) y=y+(one*sl[m-1]-two*cl[m-1])*fm*p[k-1]/st;
            else y=y+(one*sl[m-1]-two*cl[m-1])*q[k-1]*ct;
            l=l+2;
        }
        else
        {
            fn=n;
            x=x+ one*q[k-1];
            z=z- (fn+1.0)*one*p[k-1];
            l=l+1;
        }
        m=m+1;
    }
    one=x;
    x = x*cd + z*sd;
    z = z*cd - one*sd;
    magnetic_field.vec[0]=x;
    magnetic_field.vec[1]=y;
    magnetic_field.vec[2]=z;
    return magnetic_field;
}
