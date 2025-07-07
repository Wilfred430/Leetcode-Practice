/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> m;
        for (auto it : s)
        {
            if (m.find(it) == m.end())
            {
                m[it] = 1;
            }
            else
            {
                ++m[it];
            }
        }
        int len = 0;
        bool odd = false;
        for (auto it : m)
        {
            len += (it.second / 2) * 2;
            if (it.second % 2 == 1)
                odd = true;
        }

        if (odd)
            return len + 1;

        return len;
    }
};
// @lc code=end
