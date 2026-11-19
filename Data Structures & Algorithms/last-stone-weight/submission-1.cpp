class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            auto stone1 = pq.top();
            pq.pop();
            auto stone2 = pq.top();
            pq.pop();
            
            if (stone1 != stone2) {
                pq.push(stone1 - stone2);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
