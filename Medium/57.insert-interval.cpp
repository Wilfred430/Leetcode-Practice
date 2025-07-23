/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] < b[1]; });

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
