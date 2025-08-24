/*
 * @lc app=leetcode id=2469 lang=cpp
 *
 * [2469] Convert the Temperature
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius+273.15,celsius*1.8+32.0};
    }
};
// @lc code=end

