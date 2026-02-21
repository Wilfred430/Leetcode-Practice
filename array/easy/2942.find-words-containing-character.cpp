/*
 * @lc app=leetcode id=2942 lang=cpp
 *
 * [2942] Find Words Containing Character
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        vector<int> result;
        
        for(int i=0;i<words.size();++i)
        {
            if(words[i].find(x) != words[i].npos) result.push_back(i);
        }

        return result;
    }
};
// @lc code=end

