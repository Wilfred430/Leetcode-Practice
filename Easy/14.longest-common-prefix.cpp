/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ss = "";
        int j = 0;
        while(1)
        {
            char test;
            if(j != strs[0].length())
            {
                test = strs[0][j];
            }else
            {
                return ss;
            }
            for(int i=1;i<strs.size();i++)
            {
                if (j == strs[i].length())
                {
                    return ss;
                }else
                {
                    if(strs[i][j] != test)
                    {
                        return ss;
                    }
                }
            }
            ss += test;
            j++;
        }
    }
};
// @lc code=end

