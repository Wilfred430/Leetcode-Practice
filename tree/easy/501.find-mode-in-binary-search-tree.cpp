/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    TreeNode *prev = nullptr;
    int max = 0;
    vector<int> result;
    int count;

public:
    vector<int> findMode(TreeNode *root)
    {
        inorder(root);
        return this->result;
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (prev && root->val == prev->val)
        {
            this->count++;
        }
        else
        {
            this->count = 1;
        }
        if (this->count == this->max)
        {
            result.push_back(root->val);
        }
        else if (this->count > this->max)
        {
            result.clear();
            result.push_back(root->val);
            this->max = this->count;
        }
        this->prev = root;
        inorder(root->right);
        
    }
};
// @lc code=end
