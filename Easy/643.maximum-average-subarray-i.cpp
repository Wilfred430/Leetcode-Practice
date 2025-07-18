/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        double sum = 0;

        // 計算前 k 個元素的總和
        for (int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }

        double max_sum = sum;

        // 從第 k 個元素開始滑動視窗
        for (int i = k; i < n; ++i)
        {
            sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, sum);
        }

        return max_sum / k;
    }
};
// @lc code=end
