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
    int kthSmallest(TreeNode* root, int k) {
        pair<int, int> trace{k, -1};
        dfs(root, trace);
        return trace.second;
    }

private:
    void dfs(TreeNode* node, pair<int, int> &trace) {
        if (!node) {
            return;
        }

        dfs(node->left, trace);
        
        if (trace.first == 0) {
            return;
        }

        if (--trace.first == 0) {
            trace.second = node->val;
            return;
        }

        dfs(node->right, trace);
    }
};
