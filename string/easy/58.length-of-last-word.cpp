/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {}
        return tmp.length();
    }
};
// @lc code=end
