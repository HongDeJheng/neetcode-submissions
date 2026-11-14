class UnionFind {
public:
    explicit UnionFind(int n) : groups(n), parent(n), count(n, 1), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(const int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(const int x, const int y) {
        auto parentX = find(x);
        auto parentY = find(y);
        
        if (parentX == parentY) {
            return false;
        }

        // Union by rank: combine shorter tree into taller one
        if (count[parentX] < count[parentY]) {
            swap(parentX, parentY);
        }

        parent[parentY] = parentX;
        count[parentX] += count[parentY];
        if (rank[parentX] == rank[parentY]) {
            ++rank[parentX];
        }

        --groups;

        return true;
    }

    inline int getGroups() const noexcept {return groups;}
    inline void subtractGroups() {--groups;}

private:
    vector<int> parent;
    vector<int> count;
    vector<int> rank;   // rank can be considered as a tree height
    int groups;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int n = grid.size();
        if (n == 0) {
            return 0;
        }

        const int m = grid[0].size();
        UnionFind uf(n * m);

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < m; ++col) {
                if (grid[row][col] == '0') {
                    uf.subtractGroups();    // water shouldn't be counted
                }
                else {
                    if (int prevRow = row - 1; prevRow >= 0 && grid[prevRow][col] == '1') {
                        uf.unite(row * m + col, prevRow * m + col);
                    }

                    if (int prevCol = col - 1; prevCol >= 0 && grid[row][prevCol] == '1') {
                        uf.unite(row * m + col, row * m + prevCol);
                    }
                }
            }
        }

        return uf.getGroups();
    }
};
