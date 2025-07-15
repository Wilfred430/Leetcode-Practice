/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        auto isVowel = [](char c)
        {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        int left = 0, right = s.length() - 1;
        while (left < right)
        {
            if (!isVowel(s[left]))
                ++left;
            if (!isVowel(s[right]))
                --right;
            if (isVowel(s[left]) && isVowel(s[right]))
            {
                swap(s[right], s[left]);
                ++left;
                --right;
            }
        }

        return s;
    }
};
// @lc code=end
