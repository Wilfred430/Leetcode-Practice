/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (nums[i])
            {
                int con = 0;
                while (i < len && nums[i])
                {
                    ++con;
                    ++i;
                }
                if (con > max)
                {
                    max = con;
                }
            }
        }

        return max;
    }
};
// @lc code=end
