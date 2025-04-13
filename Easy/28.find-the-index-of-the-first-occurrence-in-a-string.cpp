/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include<cstring>

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        size_t pos =  haystack.find(needle);
        if(pos == haystack.npos)
        {
            return -1;
        }else
        {
            return pos;
        }
    }
};
// @lc code=end

