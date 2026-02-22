/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        unsigned tmp = 1;
        while(tmp<=n) tmp <<= 1; // shift left and assign

        return (tmp-1)^n;
    }
};
// @lc code=end

