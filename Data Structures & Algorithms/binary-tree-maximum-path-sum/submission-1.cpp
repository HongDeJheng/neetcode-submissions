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
    int maxPathSum(TreeNode* root) {
        int curMax = root->val;
        dfs(root, curMax);
        return curMax;
    }

private:
    int dfs(TreeNode* node, int &curMax) {
        if (!node) {
            return 0;
        }

        auto maxL = max(0, dfs(node->left, curMax));
        auto maxR = max(0, dfs(node->right, curMax));
        curMax = max(curMax, node->val + maxL + maxR);
        return node->val + max(maxL, maxR);
    }
};
