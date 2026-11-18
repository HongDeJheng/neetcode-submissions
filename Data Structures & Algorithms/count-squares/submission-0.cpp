class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ++pointCnt[point.front()][point.back()];
    }
    
    int count(vector<int> point) {
        int total = 0;
        auto x1 = point.front();
        auto y1 = point.back();

        if (auto y = pointCnt.find(x1); y != pointCnt.end()) {
            for (const auto& [y2, cnt] : y->second) {
                int len = y2 - y1;
                if (len == 0) {
                    continue;
                }

                int x3 = x1 + len, x4 = x1 - len;
                for (auto x : {x3, x4}) {
                    if (auto another = pointCnt.find(x); another != pointCnt.end()) {
                        if (auto anotherY1 = another->second.find(y1), anotherY2 = another->second.find(y2);
                            anotherY1 != another->second.end() && anotherY2 != another->second.end()) {
                            total += cnt * anotherY1->second * anotherY2->second;
                        }
                    }
                }
            }
        }

        return total;
    }

private:
    unordered_map<int, unordered_map<int, int>> pointCnt;
};
