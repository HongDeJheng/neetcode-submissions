class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curMin = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            curMin = min(curMin, prices[i]);
            profit = max(profit, prices[i] - curMin);
        }

        return profit;
    }
};
