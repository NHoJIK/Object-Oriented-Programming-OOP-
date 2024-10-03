/**
 * @file    StringWrapper.h
 * @brief   This is the header file for the string wrapper. Class definition 
 *          for class StirngWrapper.
 *
 *          This file contains the class definition of StringWrapper. It 
 *          contains get, set, write and read function prototype in public and
 *           arry[max_capacity] in private of the class definition.
 * 
 * @author  Amit Singh Kathayat
 * @date    9/21/2020
 */
//includes guards
#ifndef STRINGWRAPPER_H
#define STRINGWRAPPER_H
#include <iostream>

class StringWrapper
{
    public:
        StringWrapper(const char qualified_string[]);
        const static int max_capacity = 1048576; // 1MiB in bytes = 10242 bytes
        char get(int index);
        void set(int index, char value);
        void write(std::ostream& strm=std::cout) const;
        void readline(std::istream& strm=std::cin, char delim='\n');

    private:
        char array[max_capacity];    // internal storage (partially-filled array)
};

#endif