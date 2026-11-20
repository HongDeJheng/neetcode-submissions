class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m + 1, vector<int>(n + 1));
        paths[m - 1][n - 1] = 1;

        for (int row = m - 1; row >= 0; --row) {
            for (int col = n - 1; col >= 0; --col) {
                paths[row][col] += paths[row + 1][col] + paths[row][col + 1];
            }
        }

        return paths[0][0];
    }
};
