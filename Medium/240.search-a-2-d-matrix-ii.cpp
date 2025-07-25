/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, const int &target)
    {
        // int col = matrix[0].size();
        // int row = matrix.size();
        // int com = min(col, row);

        // if (row > col)
        // {
        //     for (int i = 0; i < com; ++i)
        //     {
        //         if (matrix[i][i] == target)
        //         {
        //             return true;
        //         }
        //         else if (matrix[i][i] > target)
        //         {
        //             return check(matrix, target, i, i);
        //         }
        //     }

        //     for (int i = com; i < row; ++i)
        //     {
        //         if (matrix[i][col - 1] == target)
        //         {
        //             return true;
        //         }
        //         else if (matrix[i][col - 1] > target)
        //         {
        //             return check(matrix, target, i, col - 1);
        //         }
        //     }
        // }
        // else if (row < col)
        // {
        //     for (int i = 0; i < com; ++i)
        //     {
        //         if (matrix[i][i] == target)
        //         {
        //             return true;
        //         }
        //         else if (matrix[i][i] > target)
        //         {
        //             return check(matrix, target, i, i);
        //         }
        //     }

        //     for (int i = com; i < col; ++i)
        //     {
        //         if (matrix[row - 1][i] == target)
        //         {
        //             return true;
        //         }
        //         else if (matrix[row - 1][i] > target)
        //         {
        //             return check(matrix, target, row - 1, i);
        //         }
        //     }
        // }
        // else
        // {
        //     for (int i = 0; i < com; ++i)
        //     {
        //         if (matrix[i][i] == target)
        //         {
        //             return true;
        //         }
        //         else if (matrix[i][i] > target)
        //         {
        //             return check(matrix, target, i, i);
        //         }
        //     }
        // }

        // return false;

        int row = 0;
        int col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                --col; 
            }
            else
            {
                ++row;
            }
        }
        return false;
    }

    // bool check(vector<vector<int>> &matrix, const int &target, const int &x, const int &y)
    // {
    //     for (int i = 0; i < x; ++i)
    //     {
    //         if (matrix[i][y] == target)
    //         {
    //             return true;
    //         }
    //         else if (matrix[i][y] > target)
    //         {
    //             break;
    //         }
    //     }

    //     for (int i = 0; i < y; ++i)
    //     {
    //         if (matrix[x][i] == target)
    //         {
    //             return true;
    //         }
    //         else if (matrix[x][i] > target)
    //         {
    //             break;
    //         }
    //     }

    //     return false;
    // }
};
// @lc code=end
