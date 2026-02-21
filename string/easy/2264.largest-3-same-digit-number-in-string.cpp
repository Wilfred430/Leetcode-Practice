/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string ans = "";
        for (int i = 0; i <= num.length() - 3; i++)
        {
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
            {
                string curr = num.substr(i, 3);
                if (ans.empty() || curr > ans)
                {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
