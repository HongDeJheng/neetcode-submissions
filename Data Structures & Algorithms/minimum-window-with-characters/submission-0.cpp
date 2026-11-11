class Solution {
public:
    string minWindow(string s, string t) {
        const int s_len = s.length();
        const int t_len = t.length();

        if (s_len < t_len) {
            return "";
        }

        unordered_map<char, int> t_count;
        for (auto c : t) {
            ++t_count[c];
        }

        int left = 0, exists = 0, require = t_count.size();
        pair<int, int> curMin = {0, INT_MAX};
        unordered_map<char, int> s_count;
        for (int i = 0; i < s_len; ++i) {
            auto c = s[i];
            ++s_count[c];

            if (t_count.count(c) && s_count[c] == t_count[c]) {
                exists++;
            }

            while (exists == require) {
                if (i - left + 1 < curMin.second) {
                    curMin = {left, i - left + 1};
                }

                --s_count[s[left]];
                if (t_count.count(s[left]) && s_count[s[left]] < t_count[s[left]]) {
                    --exists;
                }
                ++left;
            }
        }

        return curMin.second == INT_MAX ? "" : s.substr(curMin.first, curMin.second);
    }
};
