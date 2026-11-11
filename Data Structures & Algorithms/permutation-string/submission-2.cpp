class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int s1_len = s1.length();
        const int s2_len = s2.length();

        if (s1_len > s2_len) {
            return false;
        }

        auto s1_count = getCount(s1);
        for (int i = 0; i <= s2_len - s1_len; ++i) {
            if (s1_count[s2[i] - 'a'] == 0) {
                continue;
            }

            auto s2_count = getCount(s2.substr(i, s1_len));
            if (s1_count == s2_count) {
                return true;
            }
        }

        return false;
    }

private:
    vector<int> getCount(const string& s) {
        vector<int> count(26);
        for (auto c : s) {
            ++count[c - 'a'];
        }

        return count;
    }
};
