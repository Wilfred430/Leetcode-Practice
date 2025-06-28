/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> path;
        DFS(candidates, target, 0, path, result);

        return result;
    }

    void DFS(const vector<int> &candidates, const int target, const int start, vector<int> &path, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(path);
        }
        else if (target < 0)
        {
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            path.push_back(candidates[i]);
            DFS(candidates,target-candidates[i],i,path,result);
            path.pop_back();
        }
    }
};
// @lc code=end
