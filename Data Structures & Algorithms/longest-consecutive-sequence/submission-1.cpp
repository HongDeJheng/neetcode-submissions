class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> lengths;
        int res{};

        for (auto num : nums) {
            if (!lengths[num]) {
                lengths[num] = lengths[num - 1] + 1 + lengths[num + 1];
                lengths[num - lengths[num - 1]] = lengths[num];
                lengths[num + lengths[num + 1]] = lengths[num];
                res = max(res, lengths[num]);
            }
        }

        return res;
    }
};
