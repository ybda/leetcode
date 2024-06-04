#include <cstdio>
#include "util.h"

int search(int *arr, int l, int r, int num) {
    static int mid, val;
    if (l <= r) {
        mid = (l + r) / 2;
        val = arr[mid];
        if (val > num) return search(arr, l, mid - 1, num);
        if (val < num) return search(arr, mid + 1, r, num);
        return mid;
    }

    return -1;
}

int search(int* nums, int numsSize, int target) {
    return search(nums, 0, numsSize-1, target);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 8;

    std::cout << "Original array: " << util::arrToStr(arr, size) << "\n";

    // Perform binary search
    int index = search(arr, size, num);

    if (index != -1)
        printf("%d found at index %d.", num, index);
    else
        printf("%d not found in the array.", num);
}