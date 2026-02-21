/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int col = grid[0].size();
        int row = grid.size();
        int count = 0;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    BFS(grid, i, j);
                    ++count;
                }
            }
        }

        return count;
    }

    void BFS(vector<vector<char>> &grid, const int &x, const int &y)
    {
        int col = grid[0].size();
        int row = grid.size();

        for (auto it : dir)
        {
            int nx = x + it.first;
            int ny = y + it.second;

            if(nx < 0 || nx >= row || ny < 0 || ny >= col)
            {
                continue;
            }

            if(grid[nx][ny] == '1')
            {
                grid[nx][ny] = '0';
                BFS(grid,nx,ny);
            }
        }
    }
};
// @lc code=end
