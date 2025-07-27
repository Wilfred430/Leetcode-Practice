/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // int majorityElement(vector<int> &nums)
    // {
    //     sort(nums.begin(), nums.end());
    //     int Max = 0;
    //     int count = 1;
    //     int result = nums[0];
    //     for (int i = 1; i < nums.size(); ++i)
    //     {
    //         if (nums[i] != nums[i - 1])
    //         {
    //             if (count > Max)
    //             {
    //                 Max = count;
    //                 result = nums[i - 1];
    //             }
    //             count = 1;
    //         }
    //         else
    //         {
    //             ++count;
    //         }
    //     }

    //     if (count > Max)
    //     {
    //         result = nums[nums.size()-1];
    //     }

    //     return result;
    // }
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
            else if (nums[i] == candidate)
            {
                ++count;
            }
            else
            {
                --count;
            }
        }

        return candidate;
    }

};

    // @lc code=end
