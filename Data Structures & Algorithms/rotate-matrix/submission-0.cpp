class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        transpose(matrix);
    }

private:
    void transpose(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();

        for (int row = 0; row < rows; ++row) {
            for (int col = row + 1; col < cols; ++col) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};
