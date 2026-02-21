/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // vector<string> generateParenthesis(int n)
    // {
    //     vector<string> v;
    //     vector<char> tmp;
    //     for (int i = 0; i < n; ++i)
    //     {
    //         tmp.push_back('(');
    //         tmp.push_back(')');
    //     }

    //     do
    //     {
    //         if (Valid(tmp))
    //         {
    //             string empty = "";
    //             for (int i = 0; i < 2 * n; ++i)
    //             {
    //                 empty = empty + tmp[i];
    //             }
    //             v.push_back(empty);
    //         }
    //     } while (next_permutation(tmp.begin(), tmp.end()));

    //     return v;
    // }

    // bool Valid(const vector<char>& tmp)
    // {
    //     stack<char> s;
    //     s.push(tmp[0]);

    //     for(int i=1;i<tmp.size();++i)
    //     {
    //         if(s.top() == '(' && tmp[i] == ')')
    //         {
    //             s.pop();
    //         }else
    //         {
    //             s.push(tmp[i]);
    //         }
    //     }

    //     return s.empty();
    // }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current = "";
        Backtrack(result, current, 0, 0, n);
        return result;
    }

    void Backtrack(vector<string> &result, const string &cur, const int &left, const int &right, const int &max)
    {
        if (cur.length() == max * 2)
        {
            result.push_back(cur);
            return;
        }

        if (left < max)
        {
            Backtrack(result, cur + "(", left + 1, right, max);
        }
        if (right < left)
        {
            Backtrack(result, cur + ")", left, right + 1, max);
        }
    }
};
// @lc code=end
