
/**
 * @file    quicksort_bad.h
 * @brief   This file contains temlpated version of bad quick sort.
 *
 * The bad quick sort
 *
 * @author  Kijohn Byanjankar
 * @date    May 03, 2023
 */

#ifndef BAD_QUICKSORT_H_
#define BAD_QUICKSORT_H_

#include <iostream>
#include <utility> 
#include <cstdlib> 
#include <ctime>   

template <typename T>
int badpartition(T arr[], int l, int r) {// l = left and r = right
    int piviot = l + std::rand() % (r - l + 1);
    T pivot_value = arr[piviot];//bad partition
    std::swap(arr[piviot], arr[l]);
    piviot = l;
    int i = l + 1;
    int j = r;
    while (true) {
        while (i <= j && arr[i] < pivot_value) {
            i++;
        }
        while (i <= j && arr[j] > pivot_value) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
    std::swap(arr[piviot], arr[j]);
    return j;
}

template <typename T>
void bad_quicksort(T arr[], int l, int r) {
    if (l < r) {// tamplating the file from the type T for quicksort of bad
        int division = badpartition(arr, l, r);
        bad_quicksort(arr, l, division - 1);
        bad_quicksort(arr, division + 1, r);
    }
}

template <typename T>

void bad_quicksort(T arr[], int size) {
    std::srand(std::time(nullptr)); // generates the random number
    bad_quicksort(arr, 0, size - 1);
}

#endif