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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serializer(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializer(ss);
    }

private:
    void serializer(TreeNode* node, stringstream &ss) {
        if (!node) {
            ss << "# ";
            return;
        }

        ss << to_string(node->val) << " ";
        serializer(node->left, ss);
        serializer(node->right, ss);
    }

    TreeNode* deserializer(stringstream& ss) {
        string val;
        ss >> val;

        if (val == "#") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializer(ss);
        node->right = deserializer(ss);

        return node;
    }
};
