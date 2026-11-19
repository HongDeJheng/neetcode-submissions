class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> dests;

        for (const auto& time : times) {
            // {time, dest}
            dests[time[0]].push_back({time[2], time[1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        unordered_set<int> visited;
        int totalTime = 0;

        while (!minHeap.empty()) {
            auto [time, node] = minHeap.top();
            minHeap.pop();

            if (visited.count(node)) {
                continue;
            }

            visited.insert(node);
            totalTime = time;

            if (!dests.count(node)) {
                continue;
            }

            for (const auto& [travelTime, nextNode] : dests[node]) {
                if (!visited.count(nextNode)) {
                    // Accumulated travel time to next node
                    minHeap.push({time + travelTime, nextNode});
                }
            }
        }

        return visited.size() == n ? totalTime : -1;
    }
};
