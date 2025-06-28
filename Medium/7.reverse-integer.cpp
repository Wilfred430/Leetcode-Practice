/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8)) return 0;
            res = res * 10 + digit;
        }
        return res;
    }
};
// @lc code=end
