/*
 * @lc app=leetcode id=3110 lang=cpp
 *
 * [3110] Score of a String
 */

// @lc code=start
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {

        int result = 0;
        for(int i=0;i<s.length()-1;++i)
        {
            result+=abs(s[i]- s[i+1]);
        }

        return result;
    }
};
// @lc code=end

