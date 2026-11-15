class UnionFind {
public:
    UnionFind(int n) : parent(n), count(n, 1), groups(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    inline int getGroups() const {return groups;}

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int x, int y) {
        auto px = find(x);
        auto py = find(y);

        if (px == py) {
            return false;
        }

        if (count[px] < count[py]) {
            swap(px, py);
        }

        parent[py] = px;
        count[px] += count[py];
        --groups;

        return true;
    }

private:
    vector<int> parent;
    vector<int> count;
    int groups;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);

        for (auto &edge : edges) {
            uf.unite(edge.front(), edge.back());
        }

        return uf.getGroups();
    }
};
