/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int count = 0;
        int len = columnTitle.size();
        for (int i = len - 1; i >= 0; --i)
        {
            count += (columnTitle[i] - 'A' + 1) * pow(26, (len - 1) - i);
        }

        return count;
    }
};
// @lc code=end
