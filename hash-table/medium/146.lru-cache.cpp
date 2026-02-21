/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
private:
    int cap;
    list<pair<int, int>> lruList;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        lruList.splice(lruList.begin(), lruList, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            mp[key]->second = value;
            lruList.splice(lruList.begin(), lruList, mp[key]);
        }
        else
        {
            if (lruList.size() == cap)
            {
                int delKey = lruList.back().first;
                mp.erase(delKey);
                lruList.pop_back();
            }

            lruList.emplace_front(key, value);
            mp[key] = lruList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
