/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        int Anum = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            if(s[i] == 'A')++Anum;
            if(s[i] == 'L')
            {
                int Lnum = 1;
                while(i+1 < len && s[i+1] == 'L')
                {
                    ++Lnum;
                    ++i;
                }
                if(Lnum >= 3) return false;
            }
            if(Anum == 2) return false;
        }

        return true;
    }
};
// @lc code=end
