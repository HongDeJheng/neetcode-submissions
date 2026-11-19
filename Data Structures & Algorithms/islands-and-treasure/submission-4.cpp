class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int distance = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                for (const auto& dir : dirs) {
                    int nextX = x + dir[0];
                    int nextY = y + dir[1];

                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n ||
                        grid[nextX][nextY] != INT_MAX) {
                        continue;
                    }

                    grid[nextX][nextY] = distance;
                    q.push({nextX, nextY});
                }
            }

            ++distance;
        }
    }
};
