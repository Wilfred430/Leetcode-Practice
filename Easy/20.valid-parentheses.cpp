/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include<iostream>
#include<sstream>
#include<stack>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m{{')','('},{']','['},{'}','{'}};
        stringstream ss(s);
        stack<char> T;
        char tmp;
        while(ss >> tmp)
        {
            if(!T.empty() && m[tmp] == T.top())
            {
                T.pop();
            }else
            {
                T.push(tmp);
            }
        }

        return T.empty();
    }
};
// @lc code=end

