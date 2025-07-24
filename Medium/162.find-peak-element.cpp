/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        vector<int> v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        return (find(nums.begin(), nums.end(), v[v.size() - 1]) - nums.begin());
    }
};
// @lc code=end
