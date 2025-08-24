/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int len = nums.size();
        for(int i=0;i<len;++i)
        {
            nums.push_back(nums[i]);
        }
        
        return nums;
    }
};
// @lc code=end

