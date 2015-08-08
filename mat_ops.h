#ifndef MAT_OPS_H
#define MAT_OPS_H
#include "data_structs.h"
MATRIX mat_mul(MATRIX, MATRIX);
MATRIX inverse (MATRIX);
MATRIX adjoint (MATRIX);
MATRIX matzero();
double determinant (MATRIX,MATRIX);
#endif // MAT_OPS_H
