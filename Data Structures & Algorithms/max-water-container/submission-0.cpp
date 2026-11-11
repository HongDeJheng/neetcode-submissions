class Solution {
public:
    int maxArea(vector<int>& heights) {
        const int n = heights.size();
        int l = 0, r = n - 1;
        int area = 0;

        while (l < r) {
            area = max(area, min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r]) {
                ++l;
            }
            else {
                --r;
            }
        }

        return area;
    }
};
