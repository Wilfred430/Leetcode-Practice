/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> stairs(n + 1, 0);
        stairs[n] = 1;
        stairs[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            stairs[i] = stairs[i + 1] + stairs[i + 2];
        }

        return stairs[0];
    }
};
// @lc code=end
