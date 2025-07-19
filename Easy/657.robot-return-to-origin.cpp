/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
#include <iostream>
#include<vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        vector<int> v(4,0);
        int len = moves.length();
        for(int i=0;i<len;++i)
        {
            if(moves[i] == 'R') ++v[0];
            else if(moves[i] == 'L') ++v[1];
            else if(moves[i] == 'U') ++v[2];
            else ++v[3];
        }

        return (v[0] == v[1]) && (v[2] == v[3]);
    }
};
// @lc code=end
