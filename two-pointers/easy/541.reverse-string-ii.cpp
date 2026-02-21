/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // string reverseStr(string s, int k)
    // {
    //     string result = "";
    //     int index;
    //     int len = s.length();
    //     for (index = 0; index * k < len; ++index)
    //     {
    //         string tmp = s.substr(index * k, k);
    //         if (index % 2 == 0)
    //         {
    //             reverse(tmp.begin(), tmp.end());
    //         }
    //         result = result + tmp;
    //     }

    //     return result;
    // }
    string reverseStr(string &s, int k)
    {
        int n = s.size();
        for (int start = 0; start < n; start += 2 * k)
        {
            int i = start;
            int j = min(start + k - 1, n - 1); // 不超出範圍
            while (i < j)
            {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
// @lc code=end
