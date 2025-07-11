/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start

#include <iostream>
#include <cmath>
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
public:
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        return Recursive(root);
    }

    int Recursive(const TreeNode *root)
    {
        if(!root->left && !root->right)
        {
            return 1;
        }

        if(root->left && root->right)
        {
            return max(Recursive(root->right),Recursive(root->left))+1;
        }else if(root->right)
        {
            return Recursive(root->right)+1;
        }else
        {
            return Recursive(root->left)+1;
        }
    }
};
// @lc code=end
