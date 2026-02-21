/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <stack>
using namespace std;

class MinStack
{
private:
    stack<int> main_stack;
    stack<int> min_stack;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        main_stack.push(val);

        if (min_stack.empty() || val <= min_stack.top())
        {
            min_stack.push(val);
        }
    }

    void pop()
    {
        if (!main_stack.empty() && main_stack.top() == min_stack.top())
        {
            min_stack.pop();
        }
        main_stack.pop();
    }

    int top()
    {
        return main_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
