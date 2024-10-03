/**
 * @file    ThinArrayWrapper.h
 * @brief   This is the header file for the ThinArrayWrapper where Class
 *          definition for strcut SuperThinArrayWrapper and ThinArrayWrapper
 *          are used.
 *
 *          This file contains the structure definition to declare the 
 *          SuperThinArrayWrapper and ThinArrayWrapper
 *
 * @author  Amit Singh Kathayat
 * @date    9/21/2020
 */

//includes guards
#ifndef THINARRAYWRAPPER_H
#define THINARRAYWRAPPER_H
//Super thin wrapper declaration
struct SuperThinArrayWrapper
{
    int array[20];
};
//Thin array declaration
struct ThinArrayWrapper
{
    const static int size = 5;
    int array[size];
};

void print_array(SuperThinArrayWrapper a);

void print_array(ThinArrayWrapper a);

void fill_array_v0(ThinArrayWrapper a);

void fill_array_v1(ThinArrayWrapper &a);

ThinArrayWrapper fill_array_v2();

#endif