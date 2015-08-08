#include "vec_ops.h"
#include "math.h"
VECTOR cross_product(VECTOR r,VECTOR v)
{
    VECTOR h;
    h.vec[0]= r.vec[1]*v.vec[2]-r.vec[2]*v.vec[1];
    h.vec[1]= r.vec[2] * v.vec[0] - r.vec[0]*v.vec[2];
    h.vec[2]= r.vec[0]*v.vec[1] - r.vec[1]*v.vec[0];
    return h;
}

VECTOR veczero()
{
    VECTOR v;
    int i;
    for(i=0; i<3; i++) v.vec[i]=0;
    return v;
}

double vec_mag(VECTOR v)
{
    return (sqrt(v.vec[0]*v.vec[0]+v.vec[1]*v.vec[1]+v.vec[2]*v.vec[2]));
}

QUATERNION vect2quat(VECTOR v)
{
    QUATERNION q;
    q.quat[0]=0;
    q.quat[1]=v.vec[0];
    q.quat[2]=v.vec[1];
    q.quat[3]=v.vec[2];
    return q;
}

