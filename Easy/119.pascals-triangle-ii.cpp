/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

    vector<vector<int>> Answer;

    Solution()
    {
        this->Answer.push_back({1});
        this->Answer.push_back({1,1});

        for(int i=2;i<=33;++i)
        {
            vector<int> result(i+1,0);
            result[0] = 1;
            result[i] = 1;
            for(int j = 1;j<i;++j)
            {
                result[j] = this->Answer[i-1][j] + this->Answer[i-1][j-1];
            }

            this->Answer.push_back(result);
        }
    }

    vector<int> getRow(int rowIndex)
    {
        return this->Answer[rowIndex];
    }
    
};
// @lc code=end
