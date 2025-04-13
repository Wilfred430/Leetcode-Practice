/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
<<<<<<< HEAD:21.merge-two-sorted-lists.cpp
/*
struct ListNode {
=======
  struct ListNode {
>>>>>>> 44992b2ae4ba63e627ed23d11953f5e2955369fb:Easy/21.merge-two-sorted-lists.cpp
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
<<<<<<< HEAD:21.merge-two-sorted-lists.cpp
*/
=======

>>>>>>> 44992b2ae4ba63e627ed23d11953f5e2955369fb:Easy/21.merge-two-sorted-lists.cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* tmp = new ListNode(0);
        ListNode* node = tmp;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                node->next = list1;
                list1 = list1->next;
            }else
            {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        node->next = list1 ? list1:list2;

        ListNode* head = tmp->next;
        delete tmp;
        return head;
    }
};
// @lc code=end

