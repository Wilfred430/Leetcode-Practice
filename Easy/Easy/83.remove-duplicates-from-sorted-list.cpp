/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
*/
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        for(ListNode* tmp = head;tmp->next!=nullptr;tmp = tmp->next)
        {
            while(tmp->next != nullptr && tmp->val == tmp->next->val)
            {
                tmp->next = tmp->next->next;
            }
        }
        return head;
    }
};
// @lc code=end

