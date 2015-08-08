#ifndef FRAME_CONV_H
#define FRAME_CONV_H
#include "data_structs.h"
#include "vec_ops.h"
#include "mat_ops.h"
MATRIX eci_orbit(double agp,double  TAnrp, double ohm, double i);
MATRIX eci_ecef(double eci[],double gst);
VECTOR ecef_lla(MATRIX ecef);
#endif // FRAME_CONV_H
