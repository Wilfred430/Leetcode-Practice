/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int count[26] = {0};

        for (char c : magazine)
        {
            count[c - 'a']++;
        }

        for (char c : ransomNote)
        {
            if (--count[c - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
