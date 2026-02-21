/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=1;i<len;i=i+2)
        {
            int tmp = nums[len -1];
            nums.pop_back();
            nums.insert(nums.begin()+i,tmp);
        }
    }
};
// @lc code=end
