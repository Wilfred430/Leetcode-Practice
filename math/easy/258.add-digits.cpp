/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        int digit = 0;
        while(num != 0)
        {
            digit+=num%10;
            num/=10;
        }

        string tmp = to_string(digit);
        if(tmp.length() > 1)
        {
            return addDigits(digit);
        }

        return digit;
    }
};
// @lc code=end
