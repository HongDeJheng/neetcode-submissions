class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n, 1);

        // Fill the array with prefix product
        for (int i = 1; i < n; ++i) {
            // This way, in each index i, the product of nums on its left excluding itself
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= postfix;
            postfix *= nums[i];     // multiply after for next num
        }

        return res;
    }
};
