/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */

// @lc code=start

// Definition for a binary tree node.
#include <iostream>
#include <string>
using namespace std;

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
    int sumRootToLeaf(TreeNode *root)
    {
        int result = 0;
        string tmp = "";
        Find(root, tmp, result);
        return result;
    }

    void Find(TreeNode *root, string &tmp, int &result)
    {
        if (!root)
            return;
        tmp += to_string(root->val);
        if (!root->left && !root->right)
        {
            result += stoi(tmp, nullptr, 2);
        }
        else
        {
            if (root->left)
                Find(root->left, tmp, result);
            if (root->right)
                Find(root->right, tmp, result);
        }
        tmp.pop_back(); // 回溯
    }
};
// @lc code=end
