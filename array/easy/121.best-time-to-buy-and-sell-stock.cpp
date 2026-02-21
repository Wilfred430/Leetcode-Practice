/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int Min = INT_MAX;
        int Max = 0;
        int len = prices.size();
        for (int i = 0; i < len; ++i)
        {
            Min = min(prices[i], Min);
            Max = max(Max,prices[i]-Min);
        }

        return Max;
    }
};
// @lc code=end
