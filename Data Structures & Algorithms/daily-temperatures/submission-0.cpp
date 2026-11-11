class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> res(n, 0);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return res;
    }
};
