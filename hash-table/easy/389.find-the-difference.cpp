/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    // char findTheDifference(string s, string t)
    // {
    //     map<char,int> m1;
    //     map<char,int> m2;
    //     int len = s.length();
    //     for(int i=0;i<len;++i)
    //     {
    //         ++m1[s[i]];
    //         ++m2[t[i]];
    //     }
    //     ++m2[t[len]];

    //     for (auto& p : m2) {
    //         if (m1[p.first] != p.second) {
    //             return p.first;
    //         }
    //     }

    //     return '\0';
    // }
    char findTheDifference(string s, string t)
    {
        char res = 0;
        for (char c : s)
            res ^= c;
        for (char c : t)
            res ^= c;
        return res;
    }
};
// @lc code=end
