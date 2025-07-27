/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }
        else if (numRows == 2)
        {
            return {{1}, {1, 1}};
        }

        vector<vector<int>> result = {{1}, {1, 1}};

        for (int i = 3; i <= numRows; ++i)
        {
            vector<int> tmp(i, 0);
            tmp[0] = 1;
            tmp[i - 1] = 1;

            int len = result.size() - 1;
            for (int j = 1; j <= i - 2; ++j)
            {
                tmp[j] = result[len][j - 1] + result[len][j];
            }

            result.push_back(tmp);
        }

        return result;
    }
};
// @lc code=end
