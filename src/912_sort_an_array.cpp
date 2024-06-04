#include <iostream>
#include "util.h"

void swap(int *nums, int i, int j) {
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
}

/*
 * knuth shuffle: O(N) time, O(1) space
 */
void shuffle(int *nums, int numsSize) {
    srand(time(NULL));
    for (int i = 0; i < numsSize; i++) {
        int j = rand() % (i + 1);
        if (i != j) {
            swap(nums, i, j);
        }
    }
}

void quicksortInternal(int *target, int left, int right) {
    if(left >= right) return;
    int lt = left, rt = right;
    int pivot = target[lt];
    for(;;) {
        while(target[lt] < pivot) lt++;
        while(pivot < target[rt]) rt--;
        if(lt >= rt) break;
        swap(target, lt, rt);
        lt++; rt--;
    }
    quicksortInternal(target, left, lt - 1);
    quicksortInternal(target, rt + 1, right);
}

/*
 * quick sort:
 *     ~ N * (N - 1) / 2 => O(N^2) time,
 *     Θ(Nlog(N)) time,
 *     Ω(Nlog(N)) time,
 *     O(1) space
 */
void quickSortArray(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    shuffle(nums, numsSize);
    quicksortInternal(nums, 0, numsSize - 1);
}

int* sortArray(int *nums, int numsSize, int *returnSize) {
    int *newNums = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        newNums[i] = nums[i];
    }

    quickSortArray(newNums, numsSize, returnSize);
    return newNums;
}

int main() {
    int arr[] = {10, 7, 8, 7, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: " << util::arrToStr(arr, size) << "\n";

    int retSize = 0;
    auto sortedArr = sortArray(arr, size, &retSize);

    std::cout << "Sorted array: " << util::arrToStr(sortedArr, retSize) << "\n";
}