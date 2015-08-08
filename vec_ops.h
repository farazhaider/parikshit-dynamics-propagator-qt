#ifndef VEC_OPS_H
#define VEC_OPS_H
#include "data_structs.h"
VECTOR cross_product(VECTOR,VECTOR);
VECTOR veczero();
QUATERNION vect2quat(VECTOR);
double vec_mag(VECTOR);
void display_vector(VECTOR);
#endif // VEC_OPS_H
