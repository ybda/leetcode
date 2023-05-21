#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum1(const std::vector<int> &nums, const int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i != j && nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {0, 0};
}

std::vector<int> twoSum(const std::vector<int> &nums, const int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
        const auto find_comp = map.find(target - nums[i]);
        if (find_comp != map.end()) {
            const int mcomp = (*find_comp).second;
            if (mcomp != i) return {i, mcomp};
        }
    }
    return {0, 0};
}

int main() {
    std::vector<int> rs = twoSum({2, 7, 11, 15}, 9);
    std::cout << rs[0] << " " << rs[1] << '\n';  // 0, 1

    rs = twoSum({3, 2, 4}, 6);
    std::cout << rs[0] << " " << rs[1] << '\n';  // 1, 2

    rs = twoSum({3, 3}, 6);
    std::cout << rs[0] << " " << rs[1] << '\n';  // 0, 1
}