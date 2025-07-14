/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        for (int i = 0; i < int(nums.size()); ++i)
        {
            if (i == int(nums.size()) - 1)
                result.push_back(to_string(nums[i]));
            else if (nums[i] + 1 != nums[i + 1])
            {
                result.push_back(to_string(nums[i]));
            }
            else
            {
                string tmp = to_string(nums[i]) + "->";
                while (i + 1 < int(nums.size()) && nums[i] + 1 == nums[i + 1])
                {
                    ++i;
                }
                result.push_back(tmp + to_string(nums[i]));
            }
        }

        return result;
    }
};
// @lc code=end
