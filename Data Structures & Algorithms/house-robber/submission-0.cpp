class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.empty() ? 0 : nums.front();
        }

        const int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);  // skip 0 rob 1 or rob 0 skip 1

        for (int i = 2; i < n; ++i) {
            // Either we don't rob previous house and rob current
            // Or rub current and previous previous house
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp.back();
    }
};
