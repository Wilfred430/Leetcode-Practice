/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // string addStrings(string num1, string num2)
    // {
    //     string result = "";
    //     int len1 = num1.length() - 1;
    //     int len2 = num2.length() - 1;
    //     int carry = 0;
    //     while (len1 != -1 || len2 != -1)
    //     {
    //         int sum = 0;
    //         if (len1 >= 0)
    //         {
    //             sum += num1[len1] - '0';
    //             --len1;
    //         }
    //         if (len2 >= 0)
    //         {
    //             sum += num2[len2] - '0';
    //             --len2;
    //         }
    //         sum += carry;
    //         result = to_string(sum % 10) + result;
    //         carry = sum / 10;
    //     }

    //     if (carry > 0)
    //         result = to_string(carry) + result;

    //     return result;
    // }

    string addStrings(string num1, string num2)
    {
        string result;
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';
            result.push_back('0' + (sum % 10));
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
