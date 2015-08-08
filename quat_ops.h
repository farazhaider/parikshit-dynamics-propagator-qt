#ifndef QUAT_OPS_H
#define QUAT_OPS_H
#include "data_structs.h"
QUATERNION angle2quat(double,double,double);
VECTOR quat2angle(QUATERNION);
QUATERNION quatmultiply(QUATERNION,QUATERNION);
QUATERNION quatconj(QUATERNION);
QUATERNION quatinv(QUATERNION);
QUATERNION qzero();
double quatsquare(QUATERNION);
double quatnorm(QUATERNION);
QUATERNION quat_subtract(QUATERNION q1,QUATERNION q2);
QUATERNION quat_add(QUATERNION q1,QUATERNION q2);
#endif // QUAT_OPS_H
