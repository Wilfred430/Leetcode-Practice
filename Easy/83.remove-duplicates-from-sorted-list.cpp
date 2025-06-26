/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while(current)
        {
            ListNode* nextNode = current->next;
            while(nextNode && nextNode->val == current->val)
            {
                nextNode = nextNode->next;
            }
            current->next = nextNode;
            current = current->next;
        }

        return head;
    }
};
// @lc code=end

