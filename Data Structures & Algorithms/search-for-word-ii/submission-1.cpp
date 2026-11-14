struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word;
};

class Trie {
private:
    TrieNode* root;

    void deleteNode(TrieNode* node) {
        for (auto child : node->children) {
            if (child.second) {
                deleteNode(child.second);
            }
        }

        delete node;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        deleteNode(root);
    }

    inline TrieNode* getRoot() {return root;}

    void add(const vector<string>& words) {
        for (const auto &word : words) {
            TrieNode* ptr = root;
            for (auto c : word) {
                if (!ptr->children[c]) {
                    ptr->children[c] = new TrieNode();
                }

                ptr = ptr->children[c];
            }

            ptr->word = word;
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int rows = board.size();
        const int cols = board[0].size();
        Trie trie;
        vector<string> res;

        trie.add(words);

        auto dfs = [&](this auto&& self, TrieNode* node, const int row, const int col) -> void {
            static constexpr int dirs[4][2] = { {0 ,1}, {0, -1}, {1, 0}, {-1, 0} };
            char orig = board[row][col];

            if (!node->word.empty()) {
                res.push_back(node->word);
                node->word = "";
            }

            board[row][col] = '#';

            for (const auto &dir : dirs) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                if (nextRow < 0 || nextRow >= rows ||
                    nextCol < 0 || nextCol >= cols ||
                    board[nextRow][nextCol] == '#') {
                    continue;
                }

                if (auto it = node->children.find(board[nextRow][nextCol]); it != node->children.end()) {
                    self(it->second, nextRow, nextCol);
                }
            }

            board[row][col] = orig;
        };

        TrieNode *root = trie.getRoot();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (auto it = root->children.find(board[i][j]); it != root->children.end()) {
                    dfs(it->second, i, j);
                }
            }
        }

        return res;
    }
};
