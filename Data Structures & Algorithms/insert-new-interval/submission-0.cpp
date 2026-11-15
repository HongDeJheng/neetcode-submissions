class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int n = intervals.size();
        vector<vector<int>> res;

        int newStart = newInterval.front();
        int newEnd = newInterval.back();

        for (int i = 0; i < n; ++i) {
            if (intervals[i].front() > newEnd) {
                res.push_back({newStart, newEnd});
                res.insert(res.end(), intervals.begin() + i, intervals.end());
                return res;
            }
            else if (intervals[i].back() < newStart) {
                res.push_back(intervals[i]);
            }
            else {
                newStart = min(newStart, intervals[i].front());
                newEnd = max(newEnd, intervals[i].back());
            }
        }

        res.push_back({newStart, newEnd});

        return res;
    }
};
