/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n))
        {
            seen.insert(n);
            int sum = 0;
            while (n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }

        return n == 1;
    }
};

// @lc code=end
