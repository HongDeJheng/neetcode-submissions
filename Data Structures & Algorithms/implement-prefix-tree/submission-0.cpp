class PrefixTree {
private:
    struct Node {
        bool isWord = false;
        Node* children[26];
    };

    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    ~PrefixTree() {
        deleteNode(root);
    }

    void deleteNode(Node* node) {
        if (!node) {
            return;
        }

        for (auto child : node->children) {
            deleteNode(child);
        }

        delete node;
    }
    
    void insert(string word) {
        Node* ptr = root;
        for (auto c : word) {
            if (!ptr->children[c - 'a']) {
                ptr->children[c - 'a'] = new Node();
            }

            ptr = ptr->children[c - 'a'];
        }

        ptr->isWord = true;
    }
    
    bool search(string word) {
        Node* ptr = root;
        for (auto c : word) {
            if (!ptr->children[c - 'a']) {
                return false;
            }

            ptr = ptr->children[c - 'a'];
        }

        return ptr->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* ptr = root;
        for (auto c : prefix) {
            if (!ptr->children[c - 'a']) {
                return false;
            }

            ptr = ptr->children[c - 'a'];
        }

        return true;
    }
};
