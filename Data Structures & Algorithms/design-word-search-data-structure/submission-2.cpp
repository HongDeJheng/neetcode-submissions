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
        int idx = 0;
        queue<Node*> q;
        q.push(root);

        while (!q.empty() && idx < len) {
            int size = q.size();
            while (size-- > 0) {
                auto curr = q.front();
                q.pop();
                auto c = word[idx];

                if (c != '.') {
                    if (!curr->children[c - 'a']) {
                        continue;
                    }

                    q.push(curr->children[c - 'a']);
                }
                else {
                    for (auto child : curr->children) {
                        if (child) {
                            q.push(child);
                        }
                    }
                }
            }

            ++idx;
        }

        if (q.empty()) {
            return false;
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr->isWord) {
                return true;
            }
        }

        return false;
    }
};
