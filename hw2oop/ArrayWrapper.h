/**
 * @file    ArrayWrapper.h
 * @brief   This is the header file for the array wrapper. Class definition 
 *          for class ArrayWrapper.
 *
 *          This file contains the class definition of ArrayWrapper to get, 
 *          set and initialize the value of the size of a array.
 *
 * @author  Amit Singh Kathayat
 * @date    9/21/2020
 */

//includes guards.
#ifndef ARRAYWRAPPER_H
#define ARRAYWRAPPER_H

class ArrayWrapper
{
public:
    ArrayWrapper(int size);

    const static int max_capacity = 262144; // 1MiB max size (1MiB / sizeof(int))
    int get_size();
    int get(int index);
    void set(int index, int value);
private:
    int array[max_capacity];    // internal storage (partially-filled array)
    int size = 0;               // logical size (how many elements are used)
};

#endif