#ifndef DATA_STRUCTS_H
#define DATA_STRUCTS_H

struct matrix
{
    double mat[3][3];
    int row,col;
};
struct Vector
{
    double vec[3];
};
struct quaternion
{
    double quat[4];
};


typedef struct matrix MATRIX;
typedef struct Vector VECTOR;
typedef struct quaternion QUATERNION;
#endif // DATA_STRUCTS_H
