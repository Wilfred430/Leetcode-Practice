/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I
 */

// @lc code=start
#include <iostream>
#include <string>
#include<cmath>
using namespace std;

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a == b) return -1;
        else return max(a.size(),b.size());
    }
};
// @lc code=end
