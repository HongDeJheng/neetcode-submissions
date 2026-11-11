class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        int l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return false;
    }
};
