/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string ss = to_string(x);
        for(int i=0;i<ss.size();i++){
            if(ss[i] != ss[ss.size()-1-i])
                return false;
        }
        return true;
    }
};
// @lc code=end