/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include <iostream>
#include <bitset>
using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        bitset<32> b(n);
        int num = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (b[i])
            {
                ++num;
            }
        }

        return num;
    }
};
// @lc code=end
