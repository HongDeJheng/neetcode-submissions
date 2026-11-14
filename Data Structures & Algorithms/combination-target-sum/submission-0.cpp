class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        auto dfs = [&](this auto&& self, vector<int>& subset, const int idx, const int current) -> void {
            if (current == target) {
                res.emplace_back(subset);
                return;
            }

            for (int i = idx; i < nums.size(); ++i) {
                if (current + nums[i] > target) {
                    return;
                }

                subset.push_back(nums[i]);
                self(subset, i, current + nums[i]); // Reuse allowed, so not incrementing idx
                subset.pop_back();
            }
        };

        sort(nums.begin(), nums.end());
        vector<int> subset;
        dfs(subset, 0, 0);

        return res;
    }
};
