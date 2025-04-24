/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int result = 0;
        for(int i=0;i<s.length();i++)
        {
            if(i+1 < s.length() && m[s[i]] < m[s[i+1]])
            {
                result += m[s[i+1]] - m[s[i]];
                i++;
            }else
            {
                result += m[s[i]];
            }
        }

        return result;
    }
};
// @lc code=end

