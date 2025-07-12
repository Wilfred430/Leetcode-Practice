/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class LRUCache
{
public:
    unordered_map<int, int> data;
    vector<bool> used;
    LRUCache(int capacity)
    {
        for (int i = 0; i < capacity; ++i)
        {
            this->data[i+1] = -1;
            this->used.push_back(false);
        }
    }

    int get(int key)
    {
        used[key-1] = true;
        return this->data.find(key)->second;
    }

    void put(int key, int value)
    {
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
