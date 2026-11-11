class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> res;

        auto skipLeft = [&](int &left, const int &right) {
            do {
                ++left;
            } while (left < right && nums[left] == nums[left - 1]);
        };

        auto skipRight = [&](const int &left, int &right) {
            do {
                --right;
            } while (left < right && nums[right] == nums[right + 1]);
        };

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    skipLeft(left, right);
                    skipRight(left, right);
                }
                else if (sum < 0) {
                    skipLeft(left, right);
                }
                else {
                    skipRight(left, right);
                }
            }
        }

        return res;
    }
};
