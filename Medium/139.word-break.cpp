/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(int(s.size()) + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && set.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end
