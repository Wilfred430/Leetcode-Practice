/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start

// Definition for singly-linked list.
#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;

        ListNode *node = head;
        stack<int> tmp;
        while (node)
        {
            tmp.push(node->val);
            node = node->next;
        }
        ListNode *head2 = new ListNode(tmp.top(), nullptr);
        tmp.pop();
        ListNode *node2 = head2;
        while (!tmp.empty())
        {
            node2->next = new ListNode(tmp.top(), nullptr);
            tmp.pop();
            node2 = node2->next;
        }

        return head2;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;

        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
};
// @lc code=end
