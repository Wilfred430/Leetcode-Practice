/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int n = s.length();

        if (s == goal)
            return true;

        for (int i = 1; i < n; ++i)
        {
            string tmp = s.substr(0, i);
            string com = s.substr(i) + tmp;

            if (com == goal)
                return true;
        }

        return false;
    }
};
// @lc code=end
