class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparator = [](const vector<int>& a, const vector<int>& b) {
            return a.front() * a.front() + a.back() * a.back() < b.front() * b.front() + b.back() * b.back();
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> maxHeap;

        for (const auto& point : points) {
            maxHeap.push(point);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(move(maxHeap.top()));
            maxHeap.pop();
        }

        return res;
    }
};
