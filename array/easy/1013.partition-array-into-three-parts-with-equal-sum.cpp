/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0)
            return false;

        int target = total / 3;
        int sum = 0, count = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == target)
            {
                count++;
                sum = 0;
            }
        }

        // 至少要找到三段
        return count >= 3;
    }
};
// @lc code=end
