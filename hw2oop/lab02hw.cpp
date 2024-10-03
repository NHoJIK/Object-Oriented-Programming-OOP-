/**
 *******************************************************************************
 * @file    lab02hw.cpp
 * @brief    Program to create a wrpper using array of numbers and print the
 *           data on the display to user by using different structure like
 *           SuperThinArrayWrapper, ThinArrayWrapper, and ArrayWrapper. 
 *           Different function are used to print the result on the display.
 *           Lastly the write and read method is use to write and read data. 
 *         
 * @remarks
 *      Course:        Computer Science , Fall 2020
 *      Due Date:      Monday, September 21
 *      Instructor:    Jason L Causey
 *
 * @author  Amit Singh Kathayat
 * @date    9/21/2020
 *******************************************************************************
**/
#include <iostream>
    using std::cout;
    using std::cin;
#include "ThinArrayWrapper.h"
#include "ArrayWrapper.h"
#include "StringWrapper.h"
#include <cstring>
#include <string>
    using std::string;
#include <stdexcept>

int main()
{   //SuperThinArrayWrapper
    SuperThinArrayWrapper SuperThinArray;

    cout << "SuperThinArray is: ";
    cout << "\n";
    //filling the array by hardcoding.
    for(int i = 0; i < 20; ++i)
    {   
        SuperThinArray.array[i] = 10 * (i + 1);
    }

    print_array(SuperThinArray);

    //ThinArrayWrapper
    ThinArrayWrapper ThinArray;

    cout << "ThinArrayWrapper is: ";
    cout << "\n";
    //Using static variable size to get value at struct position.
    for (int i = 0; i < ThinArrayWrapper::size; ++i)
    {
        ThinArray.array[i] = 10 * (i + 1);
    }

    print_array(ThinArray);

    //pass by value
    //Update value of ThinArray using pass by value.
    fill_array_v0(ThinArray);

    cout << "Array in fill array function using pass by value";
    cout << "\n";
    //print array after updating value.
    print_array(ThinArray);
    //pass by reference
    //update value of ThinArray using pass by reference.
    fill_array_v1(ThinArray);

    cout << "Array in fill array function using pass by reference";
    cout << "\n";
    //print array after updating value.
    print_array(ThinArray);

    ThinArray = fill_array_v2();

    cout << "Array after going through fill array function using initialization"
         <<  "function";
    cout << "\n";
    //print array after updating value.
    print_array(ThinArray);
    //declare an object of ArrayWrapper
    ArrayWrapper catch_example_array(20);
    for(int i = 0; i < catch_example_array.get_size(); ++i)
    {
        catch_example_array.set(i, (i+1));
    }

    int selected_index = 0;

    while(selected_index >= 0)
    {
        cout << "Enter an index to print the item. (-1 to stop): ";
        cin  >> selected_index;
        if(selected_index != -1)
        {
            try
            {
                int value = catch_example_array.get(selected_index);

                cout << "The item at index " << selected_index
                      << " is " << value << '\n';
            }

            catch(const std::out_of_range&)
            {
                cout << "The index " << selected_index 
                     << " is not a valid index.\n";
                cout << "Valid indices are 0 to "
                     << catch_example_array.get_size() - 1
                     << '\n';
            // Reset to allow the loop to continue if index was negative.
                selected_index = 0;  
            }
        }
    }
    //wrapper to write the data in the terminal
    StringWrapper my_string("Hello");
    cout << my_string.get(2);
    cout << my_string.get(0);
    cout << my_string.get(100);
    cout << my_string.get(2) ;
    cout << my_string.get(-1) ;
    my_string.set(2, 'p') ;
    my_string.write();

   return 0; 
}