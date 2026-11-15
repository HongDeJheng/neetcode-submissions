class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        pac.assign(rows, vector<bool>(cols));
        atl.assign(rows, vector<bool>(cols));

        for (int row = 0; row < rows; ++row) {
            dfs(heights, row, 0, Ocean::Pacific);
            dfs(heights, row, cols - 1, Ocean::Atlantic);
        }

        for (int col = 0; col < cols; ++col) {
            dfs(heights, 0, col, Ocean::Pacific);
            dfs(heights, rows - 1, col, Ocean::Atlantic);
        }

        vector<vector<int>> res;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (pac[row][col] && atl[row][col]) {
                    res.push_back({row, col});
                }
            }
        }

        return res;
    }

private:
    int rows;
    int cols;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> pac, atl;
    enum class Ocean {Pacific, Atlantic};
    const unordered_map<Ocean, vector<vector<bool>>*> oceans = {
        {Ocean::Pacific, &pac},
        {Ocean::Atlantic, &atl}
    };

    void dfs(const vector<vector<int>>& heights, const int row, const int col, const Ocean ocean) {
        auto visited = oceans.at(ocean);
        (*visited)[row][col] = true;

        for (auto &dir : dirs) {
            int nextRow = row + dir[0];
            int nextCol = col + dir[1];

            if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols ||
                (*visited)[nextRow][nextCol] || heights[row][col] > heights[nextRow][nextCol]) {
                continue;
            }

            dfs(heights, nextRow, nextCol, ocean);
        }
    }
};
