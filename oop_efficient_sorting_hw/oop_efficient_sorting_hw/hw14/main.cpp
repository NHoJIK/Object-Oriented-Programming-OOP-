/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   Contains the test codes for the Quicksort, Bad Quicksort and Heapsort
 *          and their timing.
 *
 * 
 * @remarks
 *      Course:        Computer Science 2124, Spring 2023
 *      Due Date:      Wednesday, May 03
 *      Instructor:    Mark Gilland
 *
 * @author  Kijohn Byanjankar
 * @date    May 03, 2023
 *******************************************************************************
**/



#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include "bad_quicksort.h"
#include "quicksort.h"
#include "heapsort.h"






//random int
void generate_random_integers(int* arr, int r) {
    std::default_random_engine rangedfromup(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, r-1);
    for (int i = 0; i < 100; ++i) {
        arr[i] = dist(rangedfromup);
    }
}
//random string
std::string randomlystringgenerator() {
    static const std::string charset = "12032190asadadsa";
    std::default_random_engine rangedfromup(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, charset.size()-1);
    std::string output;
    int length = dist(rangedfromup) % 8 + 3;
    for (int i = 0; i < length; ++i) {
        output.push_back(charset[dist(rangedfromup)]);
    }
    return output;
}

//generates random
void generate_random(double* arr, double r) {
    std::default_random_engine rangedfromup(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> dist(0, r);
    for (int i = 0; i < 100; ++i) {
        arr[i] = dist(rangedfromup);
    }
}
//generates random 
double* generate_random(int number1, double r) {

    //generates the random number from number 1 integer and to the range of r.
    double* arr = new double[number1];
    std::default_random_engine rangedfromup(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> dist(0, r);
    for (int i = 0; i < number1; ++i) {
        arr[i] = dist(rangedfromup);
    }
    return arr;
}

//an array
void randomlystringgenerator(std::string* arr) {
    for (int i = 0; i < 100; ++i) {
        arr[i] = randomlystringgenerator();
    }
}

//print_elapsed_time
void print_elapsed_time(double elapsed_time) {
    std::cout << "Elapsed time: " << elapsed_time << "s." << std::endl;
}

int main() {
    int int_arr[100];
    std::string string_arr[100];

    std::cout << "All type of sort";

    // 1st test
    generate_random_integers(int_arr, 100);
    auto start_time = std::chrono::steady_clock::now();
    quicksort(int_arr, 100);
    auto end_time = std::chrono::steady_clock::now();
    auto quicksort_time = std::chrono::duration<double>(end_time - start_time).count();

    start_time = std::chrono::steady_clock::now();
    bad_quicksort(int_arr, 100);
    end_time = std::chrono::steady_clock::now();
    auto bad_quicksort_time = std::chrono::duration<double>(end_time - start_time).count();

    generate_random_integers(int_arr, 100);
    start_time = std::chrono::steady_clock::now();
    heapsorting(int_arr, 100);
    end_time = std::chrono::steady_clock::now();
    auto heapsorting_time = std::chrono::duration<double>(end_time - start_time).count();

    std::cout << "Test 1\t\t" << quicksort_time << "\t\t" << bad_quicksort_time << "\t\t" << heapsorting_time << "\n";

   //2nd testing
    std::fill_n(int_arr, 100, 0);
    std::default_random_engine rangedfromup(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, 999);
    for (int i = 0; i < 100; ++i) {
        int_arr[i] = dist(rangedfromup);
    }
    start_time = std::chrono::steady_clock::now();
    quicksort(int_arr, 100);
    end_time = std::chrono::steady_clock::now();
    quicksort_time = std::chrono::duration<double>(end_time - start_time).count();

    start_time = std::chrono::steady_clock::now();
    bad_quicksort(int_arr, 100);
    end_time = std::chrono::steady_clock::now();
    bad_quicksort_time = std::chrono::duration<double>(end_time - start_time).count();

    std::fill_n(int_arr, 100, 0);
    for (int i = 0; i < 100; ++i) {
        int_arr[i] = dist(rangedfromup);
    }
    start_time = std::chrono::steady_clock::now();
    heapsorting(int_arr, 100);
    end_time = std::chrono::steady_clock::now();
    heapsorting_time = std::chrono::duration<double>(end_time - start_time).count();

    std::cout << "Test 2\t\t" << quicksort_time << "\t\t" << bad_quicksort_time << "\t\t" << heapsorting_time << "\n";

    // testing 3
    double* double_arr = generate_random(100, 10000.0);

    start_time = std::chrono::steady_clock::now();
    quicksort(double_arr, 100);
    end_time = std::chrono::steady_clock::now();
    quicksort_time = std::chrono::duration<double>(end_time - start_time).count();

    start_time = std::chrono::steady_clock::now();
    bad_quicksort(double_arr, 100);
    end_time = std::chrono::steady_clock::now();
    bad_quicksort_time = std::chrono::duration<double>(end_time - start_time).count();

    delete[] double_arr;

    double_arr = generate_random(100, 10000.0);
    start_time = std::chrono::steady_clock::now();
    heapsorting(double_arr, 100);
    end_time = std::chrono::steady_clock::now();
    heapsorting_time = std::chrono::duration<double>(end_time - start_time).count();

    std::cout << "Test 3\t\t" << quicksort_time << "\t\t" << bad_quicksort_time << "\t\t" << heapsorting_time << "\n";

    delete[] double_arr;

    // Test 4: 
    randomlystringgenerator(string_arr);
    start_time = std::chrono::steady_clock::now();
    quicksort(string_arr, 100);
    end_time = std::chrono::steady_clock::now();
    quicksort_time = std::chrono::duration<double>(end_time - start_time).count();

    start_time = std::chrono::steady_clock::now();
    bad_quicksort(string_arr, 100);
    end_time = std::chrono::steady_clock::now();
    bad_quicksort_time = std::chrono::duration<double>(end_time - start_time).count();

    randomlystringgenerator(string_arr);
    start_time = std::chrono::steady_clock::now();
    heapsorting(string_arr, 100);
    end_time = std::chrono::steady_clock::now();
    heapsorting_time = std::chrono::duration<double>(end_time - start_time).count();

    std::cout << "Test 4\t\t" << quicksort_time << "\t\t" << bad_quicksort_time << "\t\t" << heapsorting_time << "\n";

    return 0;
    }





