/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int len = 1; len <= n / 2; ++len)
        {
            if (n % len != 0) continue;
            string pattern = s.substr(0, len);
            string repeated = "";
            for (int i = 0; i < n / len; ++i)
            {
                repeated += pattern;
            }
            if (repeated == s) return true;
        }
        return false;
    }
};
// @lc code=end
