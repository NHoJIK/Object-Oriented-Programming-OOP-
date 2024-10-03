/**
 * @file    ArrayWrapper.cpp
 * @brief   This files contains the method implementation for ArrayWrapper 
 *          class.
 *          
 *          This file contains different methods: get_size(),get,set method
 *           to complete the definition of the class ArrayWrapper
 *          
 * @author  Amit Singh Kathayat
 * @date    9/21/2020
 */
#include "ArrayWrapper.h"
#include <stdexcept>
//definition of ArrayWrapper to get the size of the value.
ArrayWrapper::ArrayWrapper(int val)
{
    size = val;
}
/**
 * @brief       This function helps to get the size of the value of 
 *               ArrayWrapper.
 *           
 * @return     size.
**/
int ArrayWrapper::get_size()
{
    return size;
}
/**
 * @brief       This function help to get the value of ArrayWrapper.
 *
 * @detailed    Check condition if the array is out of bond or not. If not
 *              further information is processed for the program.
 * 
 * @return       array[index].
**/
int ArrayWrapper::get(int index)
{
    if (index >= size || index < 0) 
    {
        throw std::out_of_range("Array index is out of bound");
    } 
    return array[index];
}
/**
 * @brief       This function contains the set of the value of ArrayWrapper.
 *
 * @detailed    Check condition if the set function of ArrayWrapper is out 
 *              of the bond or not.
 *
 * @return  no return.
**/
void ArrayWrapper::set(int index, int value)
{
    if (index >= size || index < 0) 
    {
        throw std::out_of_range("Array index is out of bound");
    } 
    array[index] = value;
}