/*
 * @lc app=leetcode id=1920 lang=cpp
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        // vector<int> result;
        // int len  = nums.size();
        // for(int i=0;i<len;++i)
        // {
        //     result.push_back(nums[nums[i]]);
        // }

        // return result;

        int n = nums.size();
        // Build the final value on the first iteration
        for (int i = 0; i < n; ++i)
        {
            nums[i] += 1000 * (nums[nums[i]] % 1000);
        }
        // Modified to final value on the second iteration
        for (int i = 0; i < n; ++i)
        {
            nums[i] /= 1000;
        }
        return nums;
    }
};
// @lc code=end
