class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (auto it = store.find(key); it != store.end()) {
            const auto &v = it->second;
            auto idx = upper_bound(v.begin(), v.end(), timestamp,
                                    [](int ts, pair<int, string> p){
                                        return ts < p.first;
                                    });
            return idx == v.begin() ? "" : prev(idx)->second;
        }

        return "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> store;
};
