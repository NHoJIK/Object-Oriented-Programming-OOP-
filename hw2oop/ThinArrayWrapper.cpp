/**
 * @file    ThinArrayWrapper.cpp
 * @brief   This files contains the method implementation for wrappers 
 *          struct.
 *          
 *          This file contains different implementation: print_array(),
 *          fill_array_v0, fill_array_v1,fill_array_v2.
 *          
 * @author  Amit Singh Kathayat
 * @date    9/21/2020
 */
#include <iostream>
    using std::cout;
    using std::cin;
#include "ThinArrayWrapper.h"
/**
 * @brief       This function contains the data to print in the struct 
 *               SuperThinArrayWrapper.
 *
 * @detailed    Check different conditions to print the data which is hard
 *              code value of size 20 in struct SuperThinArrayWrapper.
 * 
 * @return  no return.
**/
void print_array(SuperThinArrayWrapper a)
{
    //print array upto array size 20 for SuperThinArray
    cout << "SuperThinArray is: ";

    for (int i = 0; i < 20; ++i) //Hard code value of size 20.
    {
        cout << a.array[i] << " ";
    }

    cout << "\n";
}
/**
 * @brief       This function contains the data to print in the struct 
 *               ThinArrayWrapper.
 *
 * @detailed    Check condition to print the data in struct ThinArrayWrapper 
 *              which is print_array function for thin wrapper.
 * 
 * @return  no return.
**/
void print_array(ThinArrayWrapper a)
{
    cout << "ThinArray is: ";

    for(int i = 0; i < a.size; ++i)
    {
        cout << a.array[i] << " ";
    }

    cout << "\n";
}
/**
 * @brief       This function contains the data to print in the struct 
 *               ThinArrayWrapper using the function fill_array_v0.
 *
 * @detailed    Check condition to print the data in struct ThinArrayWrapper 
 *              which is fill_array_v0 function for thin wrapper pass by value.
 * 
 * @return  no return.
**/
void fill_array_v0(ThinArrayWrapper a)
{
    cout << "Update the values of the ThinArrayWrapper(pass by value)";
    cout << "\n";
    //using dot notation to access variable of size from object.
    for(int i = 0; i < a.size; ++i)
    {
        cout << "Enter the values " << i + 1 << ": ";
        cin >> a.array[i];
    }
}
/**
 * @brief       This function contains the data to print in the struct 
 *               ThinArrayWrapper using the function fill_array_v1.
 *
 * @detailed    Check condition to print the data in struct ThinArrayWrapper 
 *              which is fill_array_v1 function for thin wrapper pass by
 *              reference .
 * 
 * @return  no return.
**/
void fill_array_v1(ThinArrayWrapper &a)
{
    cout << "Update the values of the ThinArrayWrapper(pass by reference)";
    cout << "\n";
    //using dot notation to access variable of size from object.
    for(int i = 0; i < a.size; ++i)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> a.array[i];
    }
}
/**
 * @brief       struct to implement the function fill_array_v2().
 *
 * @detailed    Check condition to fill array by checking the update of value 
 *              in ThinArrayWrapper.
 * 
 * @return      a.
**/
ThinArrayWrapper fill_array_v2()
{
    ThinArrayWrapper a;
    cout << "Update the value of ThinArrayWrapper(initialization the object)";
    cout << "\n";
    //using dot notation to access variable of size from object.
    for (int i = 0; i < a.size; ++i)
    {
        cout << "Enter the value " << i + 1 << ": ";
        cin >> a.array[i];
    }
    return a;
}