/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return BST(nums, 0, nums.size() - 1);
    }

    TreeNode *BST(const vector<int> &nums, const int &left, const int &right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(nums[mid]);

        node->left = BST(nums, left, mid - 1);
        node->right = BST(nums, mid + 1, right);

        return node;
    }
};
// @lc code=end
