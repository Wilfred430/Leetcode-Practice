/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.empty())
            return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {

            for (int j = left; j <= right; ++j)
                result.push_back(matrix[top][j]);
            ++top;

            for (int i = top; i <= bottom; ++i)
                result.push_back(matrix[i][right]);
            --right;

            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                    result.push_back(matrix[bottom][j]);
                --bottom;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                    result.push_back(matrix[i][left]);
                ++left;
            }
        }

        return result;
    }
};

// @lc code=end
