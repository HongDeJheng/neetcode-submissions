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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        auto rootStr = serialize(root);
        auto subRootStr = serialize(subRoot);

        return rootStr.find(subRootStr) != string::npos;
    }

private:
    string serialize(TreeNode* node) {
        if (!node) {
            return "#X";
        }

        string s = "#" + to_string(node->val);
        s += serialize(node->left);
        s += serialize(node->right);

        return s;
    }
};
