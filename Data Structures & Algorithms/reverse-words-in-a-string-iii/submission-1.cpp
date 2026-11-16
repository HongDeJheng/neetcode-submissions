class Solution {
public:
    string reverseWords(string s) {
        int left = 0;

        for (int right = 0; right <= s.size(); ++right) {
            if (right < s.size() && s[right] != ' ') {
                continue;
            }

            reverse(span<char>(s.begin() + left, s.begin() + right));
            left = right + 1;
        }

        return s;
    }

private:
    void reverse(span<char> s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
