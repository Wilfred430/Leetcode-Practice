/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Trie
{
    vector<string> v;

public:
    Trie()
    {
        // empty
    }

    void insert(string word)
    {
        v.push_back(word);
    }

    bool search(string word)
    {
        return find(v.begin(), v.end(), word) != v.end();
    }

    bool startsWith(string prefix)
    {
        int len = prefix.length();
        for (auto it : v)
        {
            if (it.length() >= len && it.substr(0, len) == prefix)
            {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
