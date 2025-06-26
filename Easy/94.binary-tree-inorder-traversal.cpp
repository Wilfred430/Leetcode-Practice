/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
//Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;

        inorder(result,root);

        return result;
    }

    void inorder(vector<int>& result,TreeNode* node)
    {
        if(!node) return;
        inorder(result,node->left);
        result.push_back(node->val);
        inorder(result,node->right);
    }
};
// @lc code=end

