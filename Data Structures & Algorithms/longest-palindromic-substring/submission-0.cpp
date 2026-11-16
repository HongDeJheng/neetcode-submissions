class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }

        const int len = s.length();
        pair<int, int> longest{0, 1};

        for (int i = 1; i < len; ++i) {
            auto sameStart = expand(s, i, i);
            auto diffStart = expand(s, i - 1, i);

            if (diffStart.second > sameStart.second && diffStart.second > longest.second) {
                longest = diffStart;
            }
            else if (sameStart.second > diffStart.second && sameStart.second > longest.second) {
                longest = sameStart;
            }
        }

        return s.substr(longest.first, longest.second);
    }

private:
    pair<int, int> expand(string_view s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }

        int len = (r - 1) - (l + 1) + 1;
        return {l + 1, len};
    }
};
