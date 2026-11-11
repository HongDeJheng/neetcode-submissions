class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, squares;
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    continue;
                }

                int squareKey = ((row / 3) << 16) | (col / 3);
                auto &c = board[row][col];
                if (rows[row].count(c) || cols[col].count(c) || squares[squareKey].count(c)) {
                    return false;
                }

                rows[row].insert(c);
                cols[col].insert(c);
                squares[squareKey].insert(c);
            }
        }

        return true;
    }
};
