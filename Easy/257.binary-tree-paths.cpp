/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
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
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (!root->left && !root->right)
        {
            result.push_back(to_string(root->val));
            return result;
        }
        String(root, to_string(root->val), result);
        return result;
    }

    void String(TreeNode *root, const string tmp, vector<string> &result)
    {
        if (!root->left && !root->right)
        {
            result.push_back(tmp);
            return ;
        }
        if(root->right)
        {
            String(root->right,tmp+"->"+to_string(root->right->val),result);
        }
        if(root->left)
        {
            String(root->left,tmp+"->"+to_string(root->left->val),result);
        }
    }
};
// @lc code=end
