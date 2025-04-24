/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include<algorithm>

// @lc code=start
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

