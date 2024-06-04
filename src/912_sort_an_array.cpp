#include <iostream>
#include "util.h"

void quicksortInternal(int *target, int left, int right) {
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
    quicksortInternal(target, left, i - 1);
    quicksortInternal(target, j + 1, right);
}

void quicksort(int *target, int size) {
    quicksortInternal(target, 0, size - 1);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    quicksort(nums, numsSize);
    *returnSize = numsSize;
    return nums;
}

int main() {
    int arr[] = {10, 7, 8, 7, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: " << util::arrToStr(arr, size) << "\n";

    quicksort(arr, size);

    std::cout << "Sorted array: " << util::arrToStr(arr, size) << "\n";
}