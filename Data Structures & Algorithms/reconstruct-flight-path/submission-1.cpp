class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> flyFrom;
        for (const auto& ticket : tickets) {
            flyFrom[ticket.front()].push_back(ticket.back());
        }

        for (auto &[src, dst] : flyFrom) {
            // Descending lexicographically order
            sort(dst.rbegin(), dst.rend());
        }

        vector<string> reverseItinerary;
        stack<string> airports;
        airports.push("JFK");

        while (!airports.empty()) {
            auto airport = airports.top();

            if (flyFrom[airport].empty()) {
                reverseItinerary.push_back(airport);
                airports.pop();
            }
            else {
                airports.push(flyFrom[airport].back());
                flyFrom[airport].pop_back();
            }
        }

        return vector<string>(reverseItinerary.rbegin(), reverseItinerary.rend());
    }
};
