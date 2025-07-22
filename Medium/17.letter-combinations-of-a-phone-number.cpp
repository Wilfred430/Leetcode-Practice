/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if(digits.length() == 0)
        {
            return {};
        }
        vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string trans = "";
        Backtrack(result, 0, trans,digits, map);

        return result;
    }

    void Backtrack(vector<string> &result, const int &index, string &current, const string& digit,const vector<string> &map)
    {
        if(index == digit.length())
        {
            result.push_back(current);
            return ;
        }

        string target = map[digit[index] - '2'];
        for(auto c : target)
        {
            current.push_back(c);
            Backtrack(result,index+1,current,digit,map);
            current.pop_back();
        }
    }
};
// @lc code=end
