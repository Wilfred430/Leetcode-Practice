/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int Max = 0;
        int len = words.size();

        for (int i = 0; i < len; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (Check(words[i], words[j]))
                {
                    int Pro = words[i].size() * words[j].size();
                    Max = max(Max, Pro);
                }
            }
        }

        return Max;
    }

    bool Check(const string &a, const string &b)
    {
        bool ca[26] = {false};
        bool cb[26] = {false};

        for(auto it : a)
        {
            ca[it-'a'] = true;
        }

        for(auto it : b)
        {
            cb[it-'a'] = true;
        }

        for(int i =0;i<26;++i)
        {
            if(ca[i] && cb[i]) return false;
        }

        return true;
    }
};
// @lc code=end
