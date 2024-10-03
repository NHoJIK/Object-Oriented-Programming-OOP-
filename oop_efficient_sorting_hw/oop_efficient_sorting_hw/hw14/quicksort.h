/**
 * @file    quicksort.h
 * @brief   quicksort templated version.
 *
 * templated version of quick sort
 *
 * @author  Kijohn Byanjankar
 * @date    May 03, 2023
 */



#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <utility> 


template <typename T>
int partition(T arr[], int l, int r) {
    // Pivot element choosing
    int pivot_idx = std::rand() % (r - l + 1) + l;
    T pivot_value = arr[pivot_idx];

    // Move pivot to end
    std::swap(arr[pivot_idx], arr[r]);
    pivot_idx = l;

    //partition
    for (int i = l; i < r; i++) {
        if (arr[i] < pivot_value) {
            std::swap(arr[i], arr[pivot_idx]);
            pivot_idx++;
        }
    }
    // Move pivot to its final place
    std::swap(arr[pivot_idx], arr[r]);
    return pivot_idx;
}

template <typename T>
void quicksort(T arr[], int l, int r) {
    if (l < r) {
        int dividing = partition(arr, l, r);
        quicksort(arr, l, dividing - 1);
        quicksort(arr, dividing + 1, r);
    }
}

template <typename T>
void quicksort(T arr[], int size) {
    std::srand(std::time(nullptr)); // seed the random number generator
    quicksort(arr, 0, size - 1);
}


#endif 
