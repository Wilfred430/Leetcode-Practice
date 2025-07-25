/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    vector<int> data;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        Traversal(root);
        sort(data.begin(), data.end());
        return data[k - 1];
    }
    void Traversal(TreeNode *root)
    {
        if (root)
            data.push_back(root->val);
        else
            return;

        Traversal(root->left);
        Traversal(root->right);
    }
};
// @lc code=end
