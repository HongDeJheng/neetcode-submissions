/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto &interval : intervals) {
            minHeap.push({interval.start, 1});
            minHeap.push({interval.end, -1});
        }

        int maxRoom = 0;
        int curRoom = 0;

        while (!minHeap.empty()) {
            auto [time, op] = minHeap.top();
            minHeap.pop();

            curRoom += op;
            maxRoom = max(maxRoom, curRoom);
        }

        return maxRoom;
    }
};
