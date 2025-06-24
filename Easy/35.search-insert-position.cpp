/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target)
            {
                return i;
            }else if(nums[i] > target)
            {
                return i;
            }
        }

        return nums.size();
    }
};
// @lc code=end

