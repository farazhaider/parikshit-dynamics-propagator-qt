/****************************************************FILE DESCRIPTION*************************************************
File main.c:

Input provided:
w_0 : a constant
w_br: angular velocity body to reference frame
I: inertia matrix
e: contains yaw pitch roll respectively
Td: disturbance torque

Output:
Data files w_bi.txt,q_bi.txt,q_err.txt,w_err.txt,q_ref.txt
*********************************************************************************************************************/



#include "adcs_engine.h"
int main()
{
   adcs_engine(1,6073*8);
   return 0;
}



