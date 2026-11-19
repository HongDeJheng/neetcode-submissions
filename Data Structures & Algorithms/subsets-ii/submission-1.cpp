class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> res;
        dfs(nums, 0, subset, res);
        return res;
    }

private:
    void dfs(const vector<int>& nums, const int left, vector<int>& subset, vector<vector<int>>& res) {
        res.emplace_back(subset);

        for (int right = left; right < nums.size(); ++right) {
            if (right > left && nums[right] == nums[right - 1]) {
                continue;
            }

            subset.push_back(nums[right]);
            dfs(nums, right + 1, subset, res);
            subset.pop_back();
        }
    }
};
