/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}}; 

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int row = int(board.size());
        int col = int(board[0].size());

        for (int i = 0; i < col; ++i)
        {
            if (board[0][i] == 'O')
                BFS(board, 0, i);
        }

        for (int i = 0; i < col; ++i)
        {
            if (board[row - 1][i] == 'O')
                BFS(board, row - 1, i);
        }

        for (int i = 0; i < row; ++i)
        {
            if (board[i][col - 1] == 'O')
                BFS(board, i, col - 1);
        }

        for (int i = 0; i < row; ++i)
        {
            if (board[i][0] == 'O')
                BFS(board, i, 0);
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void BFS(vector<vector<char>> &board, const int &x, const int &y)
    {
        int row = int(board.size());
        int col = int(board[0].size());
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        stack<pair<int,int>> s;
        s.push({x,y});
        visited[x][y] = true;
        board[x][y] = 'T';

        while(!s.empty())
        {
            auto current = s.top();
            s.pop();

            for(auto it : dir)
            {
                int nx = current.first + it.first;
                int ny = current.second + it.second;

                if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

                if(!visited[nx][ny])
                {
                    if(board[nx][ny] == 'O')
                    {
                        board[nx][ny] = 'T';
                        visited[nx][ny] = true;
                        s.push({nx,ny});
                    }
                }
            }
        }
    }
};
// @lc code=end