class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        const int n = nums.size();
        int trueSum = n * (n + 1) / 2;
        return trueSum - sum;
    }
};
