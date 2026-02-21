/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class MyQueue
{
public:
    vector<int> v;
    MyQueue()
    {
        // empty constructor
    }

    void push(int x)
    {
        this->v.push_back(x);
    }

    int pop()
    {
        int tmp = v[0];
        v.erase(v.begin());
        return tmp;
    }

    int peek()
    {
        return v[0];
    }

    bool empty()
    {
        return v.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
