class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int n = board.size();
        const int m = board[0].size();
        const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto dfs = [&](this auto&& self, const int row, const int col, const int idx) -> bool {
            if (word[idx] != board[row][col] || board[row][col] == '#') {
                return false;
            }

            if (idx + 1 == word.length() && board[row][col] == word[idx]) {
                return true;
            }

            board[row][col] = '#';

            for (const auto &dir : dirs) {
                int nextRow = row + dir[0];
                int nextCol = col + dir[1];

                if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m) {
                    continue;
                }

                if (self(nextRow, nextCol, idx + 1)) {
                    return true;
                }
            }

            board[row][col] = word[idx];

            return false;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
