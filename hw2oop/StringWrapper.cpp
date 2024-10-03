/**
 * @file    StringWrapper.cpp
 * @brief   This files contains the method implementation for StringWrapper 
 *          class.
 *          
 *          This file contains different methods: get(),set(),write() and 
 *          readline() method using function.
 *          
 * @author  Amit Singh Kathayat
 * @date    9/21/2020
 */
#include "StringWrapper.h"
#include <stdexcept>
#include <cstring>
#include <iostream>
   
/**
 * @brief       This function contains the qualified string need for String 
 *               wrapper class.
 *
 * @detailed    Use the strncpy to check the max_capacity of the value in the
 *               StringWrapper class.
 *
 * @return  no return.
**/
StringWrapper::StringWrapper(const char qualified_string[])
{
    strncpy(array, qualified_string, max_capacity);
    array[max_capacity-1] = '\0';
}
/**
 * @brief       This function get the value for the StringWrapper class
 * 
 * @detailed    Check the index of the array using the static cast and 
 *             check if array index is out of bound or not.
 *
 * @return     array[index].
**/
char StringWrapper::get(int index)
{
    if (static_cast<size_t>(index) >= strlen(array) || index < 0) 
    {
        throw std::out_of_range("Array index is out of bound");
    } 
    return array[index];
}
/**
 * @brief       This function set the value for the StringWrapper class
 * 
 * @detailed    Check the index of the array using the static cast and 
 *             check if array index is out of bound or not.
 *
 * @return     no return.
**/
void StringWrapper::set(int index, char value)
{
    if (static_cast<size_t>(index) >= strlen(array) || index < 0) 
    {
        throw std::out_of_range("Array index is out of bound");
    }    
    array[index] = value;
}
/**
 * @brief       This function write the data for the StringWrapper class
 *
 * @return     no return.
**/
void  StringWrapper::write(std::ostream& strm) const
{
    strm << array;
}
/**
 * @brief       This function read the value for the StringWrapper class
 * 
 * @detailed    Check the limitation of the data for reading purpose using
 *              strlen and check if the array is out of bound or not.
 *
 * @return     array[index].
**/
void StringWrapper::readline(std::istream& strm, char delim)
{   
    strm.getline(array, max_capacity, delim);
    if (strlen(array) >= max_capacity - 1)
    {
        throw std::out_of_range("Array index is out of bound");
    }
}