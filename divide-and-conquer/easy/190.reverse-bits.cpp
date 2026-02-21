/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        string tmp = to_binary(n);
        return to_num(tmp);
    }

    string to_binary(int& num)
    {
        if (num == 0)
            return "0";

        string result = "";
        for(int i=0;i<32;++i)
        {
            result += (num%2 == 0)?'0':'1';
            num/=2;
        }

        return result;
    }

    int to_num(string& num)
    {
        int result = 0;
        int len = num.length();
        for (int i = len - 2; i > 0; --i)
        {
            result += (num[i] - '0') * pow(2, len - i-1);
        }

        return result;
    }
};
// @lc code=end
