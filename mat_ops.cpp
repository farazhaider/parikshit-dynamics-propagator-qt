#include "mat_ops.h"
#include "math.h"
#include <stdio.h>
MATRIX mat_mul(MATRIX a, MATRIX b)
{
    MATRIX sum;
    sum.row=a.row;
    sum.col=b.col;
    int i,j,k;
    for(i=0; i<sum.row; i++)
    {
        for(j=0; j<sum.col; j++)
        {
            sum.mat[i][j]=0;
            for(k=0; k<a.col; k++)
            {
                sum.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
            }
        }
    }
    return sum;
}

MATRIX adjoint(MATRIX I)
{
    MATRIX Idash;
    Idash.row=Idash.col=3;
    Idash.mat[0][0]=(I.mat[1][1]) *(I.mat[2][2]) - (I.mat[1][2]) * (I.mat[2][1]);
    Idash.mat[0][1]=(I.mat[1][2]) *(I.mat[2][0]) - (I.mat[1][0]) * (I.mat[2][2]);
    Idash.mat[0][2]=(I.mat[1][0]) *(I.mat[2][1]) - (I.mat[1][1]) * (I.mat[2][0]);
    Idash.mat[1][0]=(I.mat[2][1]) *(I.mat[0][2]) - (I.mat[2][2]) * (I.mat[0][1]);
    Idash.mat[1][1]=(I.mat[2][2]) *(I.mat[0][0]) - (I.mat[2][0]) * (I.mat[0][2]);
    Idash.mat[1][2]=(I.mat[2][0]) *(I.mat[0][1]) - (I.mat[2][1]) * (I.mat[0][0]);
    Idash.mat[2][0]=(I.mat[0][1]) *(I.mat[1][2]) - (I.mat[0][2]) * (I.mat[1][1]);
    Idash.mat[2][1]=(I.mat[0][2]) *(I.mat[1][0]) - (I.mat[0][0]) * (I.mat[1][2]);
    Idash.mat[2][2]=(I.mat[0][0]) *(I.mat[1][1]) - (I.mat[0][1]) * (I.mat[1][0]);
    return Idash;
}

double determinant(MATRIX a,MATRIX Idash)
{
    double Imod=0;
    Imod=Imod + Idash.mat[0][0]*a.mat[0][0] + Idash.mat[1][0]*a.mat[0][1] + Idash.mat[2][0]*a.mat[0][2];
    return Imod;
}

MATRIX inverse(MATRIX m)
{
    int i,j;
    MATRIX Idash=adjoint(m);
    Idash.row=Idash.col=3;
    double imod=determinant(m,Idash);

    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            Idash.mat[i][j]=Idash.mat[i][j] /imod;
    return Idash;
}

MATRIX matzero()
{
    MATRIX m;
    int i,j;
    m.row=m.col=3;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            m.mat[i][j]=0;
    return m;
}