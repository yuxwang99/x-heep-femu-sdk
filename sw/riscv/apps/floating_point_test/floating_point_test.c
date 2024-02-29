/*
* Copyright 2023 EPFL
* Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
* SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
*
* Author: Simone Machetti - simone.machetti@epfl.ch
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   float a = 0.5;
   float b = 1.3;
   printf("int a: %d\n", (int)a);
   printf("%.4f + %.4f = %.4f\n", a, b, a+b);
   printf("%f - %f = %f\n", a, b, a-b);
   printf("%f x %f = %f\n", a, b, a*b);
   printf("%f / %f = %f\n", a, b, a/b);
   return EXIT_SUCCESS;
}
