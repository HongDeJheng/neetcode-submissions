class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        // 2, 7, 1

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                // -1 because the current height of index i is smaller, can't be part of width
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
