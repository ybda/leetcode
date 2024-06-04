#include <iostream>
#include "util.h"

// C

void swap(int *nums, const int i, const int j) {
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}

void quicksortInternal(int *nums, const int left, const int right) {
    if(left >= right) return;

    int lt = left, rt = right;
    const int pivot = nums[rand() % (right - left + 1) + left];
    for(;;) {
        while(nums[lt] < pivot) lt++;
        while(pivot < nums[rt]) rt--;
        if(lt >= rt) break;
        swap(nums, lt, rt);
        lt++; rt--;
    }
    quicksortInternal(nums, left, lt - 1);
    quicksortInternal(nums, rt + 1, right);
}

/*
 * quick sort:
 *     ~ N * (N - 1) / 2 => O(N^2) time,
 *     Θ(Nlog(N)) time,
 *     Ω(Nlog(N)) time,
 *     O(1) space
 */
void quicksort(int *nums, const int numsSize, int *returnSize) {
    *returnSize = numsSize;
    srand(time(NULL));
    quicksortInternal(nums, 0, numsSize - 1);
}

int* sortArray(int *nums, const int numsSize, int *returnSize) {
    quicksort(nums, numsSize, returnSize);
    return nums;
}

int main() {
    int arr[] = {10, 7, 8, 7, 9, 1, 5};
    const int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: " << util::arrToStr(arr, size) << "\n";

    int retSize = 0;
    const auto sortedArr = sortArray(arr, size, &retSize);

    std::cout << "Sorted array: " << util::arrToStr(sortedArr, retSize) << "\n";
}