/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<int> minFreq(26, 0);
       
        for (char c : words[0]) 
        {
            minFreq[c - 'a']++;
        }
     
        for (int i = 1; i < words.size(); ++i) 
        {
            vector<int> freq(26, 0);
            for (char c : words[i]) 
            {
                freq[c - 'a']++;
            }
            for (int j = 0; j < 26; ++j) 
            {
                minFreq[j] = min(minFreq[j], freq[j]);
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; ++i) 
        {
            for (int k = 0; k < minFreq[i]; ++k) 
            {
                result.push_back(string(1, 'a' + i));
            }
        }
        return result;
    }
};
// @lc code=end

