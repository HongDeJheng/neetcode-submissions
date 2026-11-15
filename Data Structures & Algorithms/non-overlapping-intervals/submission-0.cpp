class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){return a.back() < b.back();});
        const int n = intervals.size();
        int toRemove = 0;
        int prevEnd = intervals.front().back();

        for (int i = 1; i < n; ++i) {
            if (prevEnd <= intervals[i].front()) {
                prevEnd = intervals[i].back();
            }
            else {
                ++toRemove;
            }
        }

        return toRemove;
    }
};
