class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 1) {
            return 1;
        }
        
        int count = 1;

        for (int i = 1; i < s.size(); ++i) {
            count += expand(s, i, i) + expand(s, i - 1, i);
        }

        return count;
    }

private:
    int expand(string_view s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
            ++count;
        }

        return count;
    }
};
