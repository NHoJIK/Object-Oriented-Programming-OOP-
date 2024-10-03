/**
 * @file    heapsort.h
 * @brief   Contains template and implementation for heapsort
 *
 * Templated version of heapsort
 *
 * @author  Kijohn Byanjankar
 * @date    May 03, 2023
 */

#include <functional>
#include "maxheap.h"




template <typename T>
void heapsorting(T arr[], int n) {
    toptobottomheap(arr, n);
    int right_index = n - 1;
    while (right_index > 0) {
        swap(arr[0], arr[right_index]);
        right_index--;
        maximum_heapdown_shifting(arr, 0, right_index);
    }
}

