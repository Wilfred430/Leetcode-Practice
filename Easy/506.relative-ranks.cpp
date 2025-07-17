/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int len = score.size();
        int rank = 1;
        vector<string> result(len);
        for (int i = 0; i < len; ++i)
        {
            auto it = max_element(score.begin(), score.end());
            int pos = it - score.begin();
            if (rank == 1)
            {
                result[pos] = "Gold Medal";
            }
            else if (rank == 2)
            {
                result[pos] = "Silver Medal";
            }
            else if (rank == 3)
            {
                result[pos] = "Bronze Medal";
            }
            else
            {
                result[pos] = to_string(rank);
            }
            score[pos] = -1;
            ++rank;
        }

        return result;
    }
};
// @lc code=end
