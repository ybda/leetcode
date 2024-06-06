#include <cstdio>
#include "util.h"

// C

int searchInternalRecursive(const int* nums, const int l, const int r, const int target) {
    if (l <= r) {
        const int mid = l + (r - l) / 2,
            guess = nums[mid];
        if (guess > target) return searchInternalRecursive(nums, l, mid - 1, target);
        if (guess < target) return searchInternalRecursive(nums, mid + 1, r, target);
        return mid;
    }
    return -1;
}

int searchInternalIterative(const int* nums, const int size, const int target) {
    int l = 0, r = size - 1;
    while (l <= r) {
        const int mid = l + (r - l) / 2,
            guess = nums[mid];
        if (guess > target) {
            r = mid - 1;
        }
        else if (guess < target) {
            l = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
//    return searchInternalRecursive(nums, 0, numsSize - 1, target);
    return searchInternalIterative(nums, numsSize, target);
}

int main() {
    int arr[] = {-1,0,3,5,9,12};
    int size = sizeof(arr) / sizeof(arr[0]);
    const int num = 12;

    std::cout << "Original array: " << util::arrToStr(arr, size) << "\n";

    // Perform binary search
    int index = search(arr, size, num);

    if (index != -1)
        printf("%d found at index %d.", num, index);
    else
        printf("%d not found in the array.", num);
}