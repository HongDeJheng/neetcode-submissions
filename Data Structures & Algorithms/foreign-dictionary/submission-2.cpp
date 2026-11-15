class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> chBehind;
        unordered_map<char, int> indegree;

        for (auto &word : words) {
            for (auto c : word) {
                indegree.try_emplace(c);
                chBehind.try_emplace(c);
            }
        }

        const int n = words.size();
        for (int i = 1; i < n; ++i) {
            const auto& w1 = words[i - 1];
            const auto& w2 = words[i];
            const int minLen = min(w1.length(), w2.length());

            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }

            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    if (!chBehind[w1[j]].count(w2[j])) {
                        ++indegree[w2[j]];
                        chBehind[w1[j]].insert(w2[j]);
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto &[c, d] : indegree) {
            if (d == 0) {
                q.push(c);
            }
        }

        string res{};
        while (!q.empty()) {
            auto c = q.front();
            q.pop();
            res += c;

            for (auto behind : chBehind[c]) {
                if (--indegree[behind] == 0) {
                    q.push(behind);
                }
            }
        }

        return res.length() == indegree.size() ? res : "";
    }
};
