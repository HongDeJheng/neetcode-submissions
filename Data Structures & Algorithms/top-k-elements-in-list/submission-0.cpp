class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const auto& num : nums) {
            ++count[num];
        }

        vector<vector<int>> freq(nums.size() + 1);  // max freq is all same int in nums
        for (const auto& p : count) {
            // p = {num, freq}
            freq[p.second].push_back(p.first);
        }

        vector<int> res;
        for (auto it = freq.rbegin(); it != freq.rend(), res.size() < k; ++it) {
            for (auto num : *it) {
                res.push_back(num);

                if (res.size() == k) {
                    break;
                }
            }
        }

        return res;
    }
};
