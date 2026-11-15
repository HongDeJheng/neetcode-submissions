class Solution {
public:
    vector<int> countBits(int n) {
        // 1 -> 0001: 1
        // 2 -> 0010: 1
        // 3 -> 0011: 2
        // 4 -> 0100: 1
        // 5 -> 0101: 2
        // 6 -> 0110: 2
        // 7 -> 0111: 3

        vector<int> dp(n + 1);
        auto isPowerOf2 = [](int n) {return (n & (n - 1)) == 0;};
        int prevPow2 = 0;

        for (int i = 1; i <= n; ++i) {
            if (isPowerOf2(i)) {
                prevPow2 = i;
            }

            dp[i] = 1 + dp[i - prevPow2];
        }

        return dp;
    }
};
