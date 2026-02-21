/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int len = strs[0].length();
        int result = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < strs.size() - 1; ++j)
            {
                if (strs[j][i] > strs[j + 1][i])
                {
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end
