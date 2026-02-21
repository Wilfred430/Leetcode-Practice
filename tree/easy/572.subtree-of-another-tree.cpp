/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
#include <iostream>
#include <stack>
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
public:
    // bool isSubtree(TreeNode *root, TreeNode *subRoot)
    // {
    //     stack<TreeNode *> s;
    //     s.push(root);
    //     vector<TreeNode *> v;

    //     while (!s.empty())
    //     {
    //         TreeNode *Node = s.top();
    //         if (Node->val == subRoot->val)
    //         {
    //             v.push_back(Node);
    //         }
    //         s.pop();

    //         if (Node->left)
    //             s.push(Node->left);
    //         if (Node->right)
    //             s.push(Node->right);
    //     }

    //     if (v.size() == 0)
    //         return false;

    //     for(auto it:v)
    //     {
    //         if(isSame(it,subRoot)) return true;
    //     }
    //     return false;
    // }

    // bool isSame(TreeNode *root, TreeNode *subRoot)
    // {
    //     if (!root && !subRoot)
    //         return true;
    //     if ((!root && subRoot) || (root && !subRoot))
    //         return false;
    //     if (root->val != subRoot->val)
    //         return false;
    //     return isSame(root->right, subRoot->right) && isSame(root->left, subRoot->left);
    // }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;

        // 如果當前節點相同就比較子樹是否完全相同
        if (isSame(root, subRoot))
            return true;

        // 遞迴往下比對左右子樹
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;
        if (a->val != b->val)
            return false;

        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};
// @lc code=end
