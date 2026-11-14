class WordDictionary {
private:
    struct Node {
        bool isWord = false;
        Node* children[26];
    };

    Node* root;

    void deleteNode(Node* node) {
        if (!node) {
            return;
        }

        for (auto child : node->children) {
            deleteNode(child);
        }

        delete node;
    }

public:
    WordDictionary() {
        root = new Node();
    }

    ~WordDictionary() {
        deleteNode(root);
    }
    
    void addWord(string word) {
        Node* ptr = root;
        for (auto c : word) {
            int idx = c - 'a';
            if (!ptr->children[idx]) {
                ptr->children[idx] = new Node();
            }

            ptr = ptr->children[idx];
        }

        ptr->isWord = true;
    }
    
    bool search(string word) {
        const int len = word.length();
        stack<pair<Node*, int>> st;
        st.push({root, 0});

        while (!st.empty()) {
            auto [node, idx] = st.top();
            st.pop();
            if (idx == len) {
                if (node->isWord) {
                    return true;
                }
                else {
                    continue;
                }
            }

            auto c = word[idx];
            if (c != '.') {
                if (node->children[c - 'a']) {
                    st.push({node->children[c - 'a'], idx + 1});
                }
            }
            else {
                for (auto child : node->children) {
                    if (child) {
                        st.push({child, idx + 1});
                    }
                }
            }
        }

        return false;
    }
};
