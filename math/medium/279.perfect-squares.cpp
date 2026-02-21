/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int q = 1; q * q <= i; ++q)
            {
                dp[i] = min(dp[i], dp[i - q * q] + 1);
            }
        }

        return dp[n];
    }
};
// @lc code=end
