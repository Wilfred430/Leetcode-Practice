/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <iostream>
#include <vector>
// #include <cmath>
#include<unordered_set>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // int len = nums.size();
        // for (int i = 0; i < len; ++i)
        // {
        //     for (int j = i + 1; j < min(len, i + 1 + k); ++j)
        //     {
        //         if (nums[i] == nums[j])
        //         {
        //             if (abs(i - j) <= k)
        //                 return true;
        //             else
        //                 break;
        //         }
        //     }
        // }

        // return false;

        unordered_set<int> window;

        for(int i=0;i<nums.size();++i)
        {
            if(window.count(nums[i])) return true;

            window.insert(nums[i]);

            if(window.size()>k) window.erase(nums[i-k]);
        }


        return false;
    }
};
// @lc code=end
