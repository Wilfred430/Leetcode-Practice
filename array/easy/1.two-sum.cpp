/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> ans;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (ans.find(target - nums[i]) != ans.end()) 
            {
                return {ans[target - nums[i]], i};
            }
            ans[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
