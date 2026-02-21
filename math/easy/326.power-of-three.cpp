/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;
        while (n != 1)
        {
            if (n % 3 != 0)
                return false;
            n /= 3;
        }

        return true;
    }
};
// @lc code=end
