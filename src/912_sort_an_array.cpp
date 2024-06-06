#include <iostream>
#include <cassert>
#include "util.h"

// C

void swap(int *nums, const int i, const int j) {
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}

void quicksortInternal(int *nums, const int l, const int r) {
    if (l >= r) return;

    int lp = l, rp = r;
    const int pivot = nums[rand() % (r - l + 1) + l];
    for (;;) {
        while (nums[lp] < pivot) lp++;
        while (nums[rp] > pivot) rp--;
        if (lp >= rp) break;
        swap(nums, lp, rp);
        lp++; rp--;
    }

    quicksortInternal(nums, l, lp - 1);
    quicksortInternal(nums, rp + 1, r);
}

void quicksort(int *nums, const int numsSize) {
    srand(time(NULL));
    quicksortInternal(nums, 0, numsSize - 1);
}

int* sortArray(int *nums, const int numsSize, int *returnSize) {
    *returnSize = numsSize;
    quicksort(nums, numsSize);
    return nums;
}

bool isSorted(const int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {10, 7, 8, 7, 9, 1, 5};
    const int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: " << util::arrToStr(arr, size) << "\n";

    int retSize = 0;
    const int* sortedArr = sortArray(arr, size, &retSize);

    std::cout << "Sorted array: " << util::arrToStr(sortedArr, retSize) << "\n";

    assert(isSorted(arr, size));
}