class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int size = nums.size();
        vector<vector<int>> subsets;

        for (int mask = 0; mask < (1 << size); ++mask) {
            vector<int> subset;
            for (int idx = 0; idx < size; ++idx) {
                if (mask & (1 << idx)) {
                    subset.push_back(nums[idx]);
                }
            }

            subsets.push_back(move(subset));
        }

        return subsets;
    }
};
