/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;
        int n = s.length();

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            // 回傳回文的起始位置和長度
            return make_pair(left + 1, right - left - 1);
        };

        for (int i = 0; i < n; ++i) {
            // 奇數長度
            auto [l1, len1] = expand(i, i);
            if (len1 > maxLen) {
                start = l1;
                maxLen = len1;
            }
            // 偶數長度
            auto [l2, len2] = expand(i, i + 1);
            if (len2 > maxLen) {
                start = l2;
                maxLen = len2;
            }
        }
        return s.substr(start, maxLen);
    }
};
// @lc code=end

