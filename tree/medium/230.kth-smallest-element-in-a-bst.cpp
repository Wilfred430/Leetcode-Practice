/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

// @lc code=start

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


#include <iostream>
using namespace std;

class Solution
{
    int count = 0;
    int record;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        // Traversal(root);
        // sort(data.begin(), data.end());
        // return data[k - 1];
        int result = 0;
        this->record = k;
        Inorder(root, result);
        return result;
    }
    // void Traversal(TreeNode *root)
    // {
    //     if (root)
    //         data.push_back(root->val);
    //     else
    //         return;

    //     Traversal(root->left);
    //     Traversal(root->right);
    // }

    void Inorder(TreeNode *root, int &result)
    {
        if (!root)
            return;

        Inorder(root->left, result);
        this->count++;
        if (this->record == count)
            result = root->val;
        Inorder(root->right, result);
    }
};
// @lc code=end
