class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        // dp[i] means the number of combination we can decode for s[i:]
        vector<int> dp(n + 1);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                continue;
            }

            dp[i] = dp[i + 1];
            if (i + 1 < n) {
                const int num = stoi(s.substr(i, 2));
                if (num <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp.front();
    }
};
