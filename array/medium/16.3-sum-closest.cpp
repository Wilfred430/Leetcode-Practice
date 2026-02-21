/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < N - 2; ++i) {
            int left = i + 1, right = N - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }
                if (sum < target) {
                    ++left;
                } else if (sum > target) {
                    --right;
                } else {
                    return sum; // 完全相等，直接回傳
                }
            }
        }

        return closest;

    }
};
// @lc code=end
