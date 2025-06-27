/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
#include<iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0);
        ListNode* node = &dummy;
        while(l1 || l2 || carry)
        {
            int tmp = carry;
            if(l1)
            {
                tmp += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                tmp += l2->val;
                l2 = l2->next;
            }
            node->next = new ListNode(tmp % 10);
            node = node->next;
            carry = tmp / 10;
        }
        return dummy.next;
    }
};
// @lc code=end

