class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int dollar = 1; dollar <= amount; ++dollar) {
            for (auto coin : coins) {
                if (coin <= dollar) {
                    dp[dollar] = min(dp[dollar], dp[dollar - coin] + 1);
                }
            }
        }

        return dp.back() > amount ? -1 : dp.back();
    }
};
