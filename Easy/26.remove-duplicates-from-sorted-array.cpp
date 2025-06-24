/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>
#include <map>
#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<int(nums.size());i++)
        {
            if(m.find(nums[i]) != m.end())
            {
                m[nums[i]]++;
            }else
            {
                m[nums[i]] = 0;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]] != 0)
            {
                m[nums[i]]--;
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return  nums.size();
    }
};
// @lc code=end

