/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int col = board[0].size();
        int row = board.size();

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int live = 0;
                for (auto it : dir)
                {
                    int nx = i + it.first;
                    int ny = j + it.second;

                    if (nx >= 0 && nx < row && ny >= 0 && ny < col)
                    {
                        if (board[nx][ny] == 1 || board[nx][ny] == 2)
                            ++live;
                    }
                }

                if (board[i][j] == 1)
                {
                    if (live < 2 || live > 3)
                        board[i][j] = 2; // 活 -> 死
                }
                else
                {
                    if (live == 3)
                        board[i][j] = 3; // 死 -> 活
                }
            }
        }

        // Step 2: 將狀態還原為最終狀態
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};
// @lc code=end
