/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<int> dp(n);
        vector<int> pointers(primes.size(), 0);
        vector<long> next(primes.begin(), primes.end());

        dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            long min_val = *min_element(next.begin(), next.end());
            dp[i] = (int)min_val;

            for (int j = 0; j < primes.size(); j++)
            {
                if (next[j] == min_val)
                {
                    pointers[j]++;
                    next[j] = (long)primes[j] * dp[pointers[j]];
                }
            }
        }

        return dp[n - 1];
    }
};
// @lc code=end
