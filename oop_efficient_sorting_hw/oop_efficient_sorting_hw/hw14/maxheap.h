/**
 * @file    maxheap.h
 * @brief   template of max heap
 *
 * max heap templated version
 *
 * @author  Kijohn
 * @date    May 03, 2023
 */
 
#include <functional>

template <typename T>
int parent(int i) {
    return (i - 1) / 2;
}

template <typename T>
int left(int i) {
    return 2 * i + 1;
}

template <typename T>
int right(int i) {
    return 2 * i + 2;
}

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int childmaximum_index(T* heap_arr, int size, int i) {
    int left_child_idx = left<T>(i);
    int right_child_idx = right<T>(i);

    // If left child index is out of bounds, there are no children
    if (left_child_idx >= size) {
        return -1;
    }

    // If right child index is out of bounds, left child is the only child
    if (right_child_idx >= size) {
        return left_child_idx;
    }

    // Otherwise, return the index of the larger child
    if (heap_arr[left_child_idx] > heap_arr[right_child_idx]) {
        return left_child_idx;
    } else {
        return right_child_idx;
    }
}


template<typename T>
void maximum_heapdown_shifting(T* heap_arr, int size, int i) {
    int max_child = childmaximum_index(heap_arr, size, i);

    if (max_child != -1 && heap_arr[max_child] > heap_arr[i]) {
        std::swap(heap_arr[max_child], heap_arr[i]);
        maximum_heapdown_shifting(heap_arr, size, max_child);
    }
}



template <typename T>
void max_heap_insert(T new_value, T* heap_arr, int& heap_size) {
    int i = heap_size;
    heap_arr[i] = new_value;
    while (i > 0 && std::greater<T>{}(heap_arr[i], heap_arr[parent<T>(i)])) {
        swap(heap_arr[i], heap_arr[parent<T>(i)]);
        i = parent<T>(i);
    }
    heap_size++;
}

template <typename T>
T removing_heap(T* heap_arr, int& heap_size) {
    T result = heap_arr[0];
    swap(heap_arr[0], heap_arr[heap_size-1]);
    heap_size--;
    maximum_heapdown_shifting(heap_arr, 0, heap_size-1);
    return result;
}

template <typename T>
void maximum_heap_(T arr[], int n) {
    int heap_size = 0;
    for (int i = 0; i < n; i++) {
        max_heap_insert(arr[i], arr, heap_size);
        heap_size++;
    }
}

template <typename T>
void toptobottomheap(T arr[], int n) {
    int mini_root = parent<T>(n-1);
    while (mini_root >= 0) {
        maximum_heapdown_shifting(arr, mini_root, n-1);
        mini_root--;
    }
}
