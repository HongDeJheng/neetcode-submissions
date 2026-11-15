class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        int remains[2] = {cols, rows - 1};  // {horizontal, vertical}
        const int dirs[4][2] = {
            {0, 1},     // right
            {1, 0},    // down
            {0, -1},    // left
            {-1, 0}      // up
        };
        int dirIdx = 0;
        int x = 0, y = -1;

        vector<int> res;

        while (remains[dirIdx % 2]) {
            auto remain = remains[dirIdx % 2]--;
            auto dir = dirs[dirIdx];

            while (remain-- > 0) {
                x += dir[0];
                y += dir[1];

                res.push_back(matrix[x][y]);
            }

            dirIdx = (dirIdx + 1) % 4;
        }

        return res;
    }
};
