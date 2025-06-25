/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start

#include<algorithm>
#include<iostream>
#include<string>
using namespace  std;
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string ss = s;
        reverse(ss.begin(),ss.end());

        return ss == s;
    }
};
// @lc code=end

