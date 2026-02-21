/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }
};
// @lc code=end
