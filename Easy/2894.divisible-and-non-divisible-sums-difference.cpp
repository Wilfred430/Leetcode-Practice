/*
 * @lc app=leetcode id=2894 lang=cpp
 *
 * [2894] Divisible and Non-divisible Sums Difference
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0,num2 = 0;

        num1 = (1+n)*n/2;

        int tmp = m;
        while(tmp <= n)
        {
            num2+=tmp;
            tmp+=m;
        }

        return num1 - 2*num2;
    }
};
// @lc code=end

