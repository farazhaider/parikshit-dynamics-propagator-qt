#ifndef DECLARATIONS_H
#define DECLARATIONS_H
#include "data_structs.h"
double w_bi_mag;
double w_c,zeta;
double Kpx,Kpy,Kpz,Kdx,Kdy,Kdz,Tcx,Tcy,Tcz;
VECTOR w_bi,w0,w_br,w_err,e;
VECTOR Tc,Td;
MATRIX Rx,Ry,Rz,Tbr;
MATRIX I,Idash;
QUATERNION q0, q_br, q_bi, q_dot, q_w0, q_ref, q_err, q_err_dot, q_w_bi, q_err_dot_1, q_err_dot_2;
double r[3],v[3],vr,h[3],H,N[3],angleOfIncidence,RAAN,RAAND,ex[3],E,AGP,AGPD,MA,MAD,sa,T,n,Eo;
double T1,Tf,np,Tnrp,Mnrp,Enrp,Fe,dFe,ratio,TAnrp,rTAnrp[3],p,vTAnrp[3],dRAAN,omega,dagp,argumentOfPerigee,rnew[3],vnew[3];
long int nrp;
double temp[3];
int i;
double time;
#endif // DECLARATIONS_H

