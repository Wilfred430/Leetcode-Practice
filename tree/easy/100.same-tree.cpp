/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 */

// @lc code=start

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return traversal(p,q);    
    }

    bool traversal(const TreeNode* p,const TreeNode* q)
    {
        if(!p && !q) return true;
        else if(!p || !q) return false;

        if(p->val != q->val) return false;
        
        return traversal(p->left,q->left) && traversal(p->right,q->right);
    }
};
// @lc code=end

