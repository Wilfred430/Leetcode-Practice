/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string sim = "";
        for (auto it : s)
        {
            if (isalpha(it) || isdigit(it))
                sim += tolower(it);
        }

        int len = sim.length() - 1;
        for (int i = 0, j = len; i < j; ++i, --j)
        {
            if (sim[i] != sim[j])
                return false;
        }

        return true;
    }
};
// @lc code=end
