/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
            {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] < b[1]; 
            });

        vector<vector<int>> result;

        for (auto &interval : intervals)
        {
            if (result.empty() || interval[0] > result.back()[1])
            {
                result.push_back(interval);
            }
            else
            {

                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};
// @lc code=end
