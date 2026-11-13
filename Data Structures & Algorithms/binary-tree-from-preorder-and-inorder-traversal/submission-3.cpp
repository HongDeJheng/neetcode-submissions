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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIdxs;
        const int n = inorder.size();

        for (int i = 0; i < n; ++i) {
            inorderIdxs[inorder[i]] = i;
        }

        int preIdx = 0;
        auto dfsImpl = [&](auto&& self, const int l, const int r) -> TreeNode* {
            if (l > r) {
                return nullptr;
            }

            int rootVal = preorder[preIdx++];
            TreeNode* root = new TreeNode(rootVal);
            int inIdx = inorderIdxs[rootVal];
            root->left = self(self, l, inIdx - 1);
            root->right = self(self, inIdx + 1, r);
            
            return root;
        };

        // optional: wrapper for cleaner syntax
        auto dfs = [&](const int l, const int r) {
            return dfsImpl(dfsImpl, l, r);
        };

        return dfs(0, n - 1);
    }
};
