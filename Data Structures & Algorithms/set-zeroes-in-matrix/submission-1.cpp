class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        bool firstRowHasZero = false;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    if (row > 0) {
                        matrix[row][0] = 0;
                    }
                    else {
                        firstRowHasZero = true;
                    }
                }
            }
        }

        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                if (matrix[0][col] == 0 || matrix[row][0] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }

        // In previous iteration, we set row = 0 to 0 for the col that has 0
        if (matrix[0][0] == 0) {
            for (int row = 0; row < rows; ++row) {
                matrix[row][0] = 0;
            }
        }

        if (firstRowHasZero) {
            for (int col = 0; col < cols; ++col) {
                matrix[0][col] = 0;
            }
        }
    }
};
