#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, middle;
        std::vector<int> result = { -1, -1 };
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {
                result[0] = middle; result[1] = middle;
                break;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        if (result[0] == -1) {
            return result;
        }
        
        int centre_1 = (left + right) / 2;
        int centre_2 = centre_1;

        while (left < centre_1) {
            middle = (left + centre_1) / 2;
            if (nums[middle] == target) {
                centre_1 = middle;
            }
            else {
                left = middle + 1;
            }
        }
        result[0] = left;

        while (centre_2 < right) {
            middle = (centre_2 + right) / 2;
            if (nums[middle] == target) {
                centre_2 = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        if (nums[centre_2] != target) {
            result[1] = centre_2 - 1;
        }
        else {
            result[1] = centre_2;
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums = {1};
    for (int& i : Solution::searchRange(nums, 1)) {
        std::cout << i << " ";
    }
}
