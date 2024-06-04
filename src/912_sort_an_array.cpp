#include <iostream>
#include "util.h"

static void quicksort(int *target, int left, int right) {
    if(left >= right) return;
    int i = left, j = right;
    int tmp, pivot = target[i];
    for(;;) {
        while(target[i] < pivot) i++;
        while(pivot < target[j]) j--;
        if(i >= j) break;
        tmp = target[i]; target[i] = target[j]; target[j] = tmp;
        i++; j--;
    }
    quicksort(target, left, i-1);
    quicksort(target, j+1, right);
}

static void quicksort(int *target, int size) {
    quicksort(target, 0, size - 1);
}

int main() {
    int arr[] = {10, 7, 8, 7, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: " << util::arrStr(arr, size) << "\n";

    quicksort(arr, size);

    std::cout << "Sorted array: " << util::arrStr(arr, size) << "\n";
}