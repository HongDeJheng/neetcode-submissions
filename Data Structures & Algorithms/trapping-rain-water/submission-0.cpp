class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxL = 0, maxR = 0;
        int trapped = 0;

        while (l < r) {
            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);

            trapped += (maxL < maxR) ? (maxL - height[l++]) : (maxR - height[r--]);
        }

        return trapped;
    }
};
