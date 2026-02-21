/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        while (n != 1)
        {
            if (n % 2 == 1)
                return false;
            n /= 2;
        }
        return true;
    }
};
// @lc code=end
