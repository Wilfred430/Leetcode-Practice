/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
        {
        }
        return tmp.length();
    }
};
// @lc code=end
