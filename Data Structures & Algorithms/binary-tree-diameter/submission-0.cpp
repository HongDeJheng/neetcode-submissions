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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        dfs(root, maxD);

        return maxD;
    }

private:
    int dfs(TreeNode* node, int &maxD) {
        if (!node) {
            return 0;
        }

        auto leftD = dfs(node->left, maxD);
        auto rightD = dfs(node->right, maxD);
        maxD = max(maxD, leftD + rightD);
        return 1 + max(leftD, rightD);
    }
};
