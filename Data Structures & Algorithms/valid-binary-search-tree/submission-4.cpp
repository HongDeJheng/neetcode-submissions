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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

private:
    bool dfs(TreeNode* node, long leftVal, long rightVal) {
        if (!node) {
            return true;
        }

        if (!(leftVal < node->val && node->val < rightVal)) {
            return false;
        }

        return dfs(node->left, leftVal, node->val) && dfs(node->right, node->val, rightVal);
    }
};
