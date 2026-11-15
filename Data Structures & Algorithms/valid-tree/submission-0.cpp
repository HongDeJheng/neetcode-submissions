class UnionFind {
public:
    UnionFind(int n) : parent(n), count(n, 1), rank(n, 0), groups(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    inline int getGroups() const {return groups;}

    void subtractGroups() noexcept {--groups;}

    bool unite(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) {
            return false;
        }

        if (rank[pX] < rank[pY]) {
            swap(pX, pY);
        }

        parent[pY] = pX;
        count[pX] += count[pY];
        if (rank[pX] == rank[pY]) {
            ++rank[pX];
        }

        subtractGroups();
        return true;
    }

    bool isConnected(int x, int y) {return find(x) == find(y);}

private:
    vector<int> parent;
    vector<int> count;
    vector<int> rank;
    int groups;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        UnionFind uf(n);
        for (auto &edge : edges) {
            if (!uf.unite(edge.front(), edge.back())) {
                return false;
            }
        }

        return uf.getGroups() == 1;
    }
};
