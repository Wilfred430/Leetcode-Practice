/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 */

// @lc code=start
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
    TreeNode* prev = nullptr;
    int Min = INT_MAX;
public:
    int getMinimumDifference(TreeNode *root)
    {
        inorder(root);
        return this->Min;
    }

    void inorder(TreeNode* root)
    {
        if(!root) return ;
        inorder(root->left);
        if(prev) this->Min = min(abs((root->val - prev->val)),Min);

        this->prev = root;
        inorder(root->right);
    }
};
// @lc code=end
