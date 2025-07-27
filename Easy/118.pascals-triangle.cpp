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
    // vector<vector<int>> generate(int numRows)
    // {
    //     if (numRows == 1)
    //     {
    //         return {{1}};
    //     }
    //     else if (numRows == 2)
    //    {
    //         return {{1}, {1, 1}};
    //     }

    //     vector<vector<int>> result = {{1}, {1, 1}};

    //     for (int i = 3; i <= numRows; ++i)
    //     {
    //         vector<int> tmp(i, 0);
    //         tmp[0] = 1;
    //         tmp[i - 1] = 1;

    //         int len = result.size() - 1;
    //         for (int j = 1; j <= i - 2; ++j)
    //         {
    //             tmp[j] = result[len][j - 1] + result[len][j];
    //         }

    //         result.push_back(tmp);
    //     }

    //     return result;
    // }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i)
        {
            result.push_back(vector<int>(i + 1, 1)); // 每行首尾都預設1
            for (int j = 1; j < i; ++j)
            {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j]; // 根據上一行計算
            }
        }
        return result;
    }
};
// @lc code=end
