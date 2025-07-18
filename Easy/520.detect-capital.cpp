/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int len = word.length();
        if(isupper(word[0]))
        {
            bool up = false;
            bool low = false;
            for(int i=1;i<len;++i)
            {
                if(isupper(word[i])) up = true;
                if(islower(word[i])) low = true;
                if(up && low) return false;
            }
        }else
        {
            for(int i=1;i<len;++i)
            {
                if(isupper(word[i])) return false;
            }
        }

        return true;
    }
};
// @lc code=end
