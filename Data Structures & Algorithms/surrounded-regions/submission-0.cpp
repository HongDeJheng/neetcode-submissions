class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        const int n = board.front().size();
        const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto dfs = [&board, &dirs, m, n](this auto&& self, const int x, const int y) -> void {
            board[x][y] = '#';
            for (auto &dir : dirs) {
                int nextX = x + dir[0];
                int nextY = y + dir[1];
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || board[nextX][nextY] != 'O') {
                    continue;
                }

                self(nextX, nextY);
            }
        };

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                dfs(i, 0);
            }

            if (board[i][n - 1] == 'O') {
                dfs(i, n - 1);
            }
        }

        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                dfs(0, j);
            }

            if (board[m - 1][j] == 'O') {
                dfs(m - 1, j);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
