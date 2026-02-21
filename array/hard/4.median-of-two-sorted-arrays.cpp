/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i)
        {
            result.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            result.push_back(nums2[i]);
        }

        sort(result.begin(), result.end());

        if (result.size() % 2 == 1)
        {
            return double(result[result.size() / 2]);
        }
        else
        {
            return double(result[result.size() / 2] + result[result.size() / 2 - 1])/2.0;
        }

        return 0.0;
    }
};
// @lc code=end
