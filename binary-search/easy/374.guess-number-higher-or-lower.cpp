/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
#include <iostream>
using namespace std;

int pick = 6; // 假設要猜的數字

int guess(int num)
{
    if (num > pick)
        return -1;
    if (num < pick)
        return 1;
    return 0;
}

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int result = guess(mid);
            if (result == 0)
                return mid;
            else if (result > 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
// @lc code=end
