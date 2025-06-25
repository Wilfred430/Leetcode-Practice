/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {

        string tmp = "";
        int bor = 0;
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || bor) {
            int kp_num = bor;
            if (i >= 0) kp_num += a[i--] - '0';
            if (j >= 0) kp_num += b[j--] - '0';
            tmp = to_string(kp_num % 2) + tmp;
            bor = kp_num / 2;
        }
        return tmp;
    }
};
// @lc code=end

