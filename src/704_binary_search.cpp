#include <cstdio>
#include "util.h"

// C

int searchInternal(int* nums, int l, int r, int target) {
    int mid, val;
    if (l <= r) {
        mid = (l + r) / 2;
        val = nums[mid];
        if (val > target) return searchInternal(nums, l, mid - 1, target);
        if (val < target) return searchInternal(nums, mid + 1, r, target);
        return mid;
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    return searchInternal(nums, 0, numsSize - 1, target);
}

int main() {
    int arr[] = {-1,0,3,5,9,12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 12;

    std::cout << "Original array: " << util::arrToStr(arr, size) << "\n";

    // Perform binary search
    int index = search(arr, size, num);

    if (index != -1)
        printf("%d found at index %d.", num, index);
    else
        printf("%d not found in the array.", num);
}