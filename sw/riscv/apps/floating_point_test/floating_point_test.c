/*
* Copyright 2023 EPFL
* Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
* SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
*
* Author: Simone Machetti - simone.machetti@epfl.ch
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "csr.h"


typedef enum
{
    DEC1 = 10,
    DEC2 = 100,
    DEC3 = 1000,
    DEC4 = 10000,
    DEC5 = 100000,
    DEC6 = 1000000,

} tPrecision ;

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void putLong(long x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x >= 10) 
    {
        putLong(x / 10);
    }
    putchar(x % 10+'0');
}

void putFloat( float f, tPrecision p )
{
    long i = (long)f ;
    putLong( i ) ;
    f = (f - i) * p ;
    i = abs((long)f) ;
    if( fabs(f) - i >= 0.5f )
    {
        i++ ;
    }
    putchar('.') ;
    putLong( i ) ;
}

int main(int argc, char *argv[])
{
    CSR_SET_BITS(CSR_REG_MSTATUS, (0x01 << 13));
    float a = 0.5f;
    float b = 1.31f;

    float sumAB = a + b;
    float prodAB = a * b;
    float diffAB = a - b;
    float divAB = a / b;
    printf("debug float\n");
    
    putFloat(a, DEC4);
    printf(" + ");
    putFloat(b, DEC4);
    printf(" = ");
    putFloat(sumAB, DEC4);
    putchar('\n');
    putFloat(prodAB, DEC4);
    putchar('\n');
    putFloat(diffAB, DEC5);
    putchar('\n');
    putFloat(divAB, DEC3);
    putchar('\n');

    return EXIT_SUCCESS;
}


// // A function to print a floating point number using putchar
// void putfloat(float x, int p)
// {
//     // Check if x is negative
//     if (x < 0)
//     {
//         // Print a minus sign
//         putchar('-');
//         // Make x positive
//         x = -x;
//     }

//     // Convert the integer part of x into a string of digits
//     long i = (long)x; // Get the integer part
//     char int_str[20]; // An array to store the digits
//     int len = 0; // The length of the string
//     int loop_times = 0;
//     do
//     {
//         // Get the last digit and store it in the array
//         int_str[len] = '0' + i % 10;
//         len++;
//         // Remove the last digit from i
//         i /= 10;
//         loop_times++;
//     } while (i > 0 && loop_times<5);

//     // Reverse the string of digits
//     for (int j = 0; j < len / 2; j++)
//     {
//         // Swap the elements at both ends
//         swap(&int_str[j], &int_str[len - 1 - j]);
//     }

//     // Print the string of digits
//     for (int j = 0; j < len; j++)
//     {
//         putchar(int_str[j]);
//     }

//     // Print a decimal point
//     putchar('.');

//     // Convert the fractional part of x into a string of digits
//     float f = x - (long)x; // Get the fractional part
//     char frac_str[20]; // An array to store the digits
//     len = 0; // The length of the string
    
//     while (p--)
//     {
//         // Get the first digit after the decimal point and store it in the array
//         f = (f - (long)f) * 10;
//         frac_str[len] = '0' + (long)f;
//         len++;
        

//     }
//     // Round up if necessary
//     if (fabs(f - (long)f) >= 0.5f)
//     {
//         frac_str[len - 1]++;
//     }

//     // Print the string of digits
//     for (int j = 0; j < len; j++)
//     {
//         putchar(frac_str[j]);
//     }
// }