class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums.front();
        int curSum = 0;
        for (auto num : nums) {
            curSum = max(0, curSum);
            curSum += num;
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
