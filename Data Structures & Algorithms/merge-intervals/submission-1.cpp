class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());
        
        for (auto &interval : intervals) {
            if (res.empty()) {
                res.push_back(interval);
                continue;
            }

            if (res.back().back() < interval.front()) {
                res.push_back(interval);
            }
            else {
                res.back().front() = min(res.back().front(), interval.front());
                res.back().back() = max(res.back().back(), interval.back());
            }
        }

        return res;
    }
};
