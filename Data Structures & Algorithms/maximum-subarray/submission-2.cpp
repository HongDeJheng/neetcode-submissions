class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int curSum = 0;
        for (auto num : nums) {
            curSum = max(num, curSum + num);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
