/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static bool Compare(const string& a,const string &b)
    {
        return a + b > b + a;
    }

    string largestNumber(vector<int> &nums)
    {
        vector<string> final;
        for (auto it : nums)
            final.push_back(to_string(it));
        sort(final.begin(), final.end(), Compare);

        string result = "";
        for (auto it : final)
            result += it;

        if(result[0] == '0') return "0";
        return result;
    }
};
// @lc code=end
