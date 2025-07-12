/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto it : nums)
        {
            if(s.find(it) != s.end()) return true;
            else s.insert(it);
        }

        return false;
    }
};
// @lc code=end

