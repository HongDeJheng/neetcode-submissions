class Solution {
public:
    vector<vector<string>> partition(string s) {
        const int sLen = s.length();
        vector<vector<bool>> isPali(sLen, vector<bool>(sLen));

        // Outer loop to loop thru all possible length of substrings
        for (int len = 1; len <= sLen; ++len) {
            // Inner loop to loop thru all possible left index
            for (int left = 0; left <= sLen - len; ++left) {
                const int right = left + len - 1;
                // current left to right is a palindrome only when
                //  1. s[left] == s[right]
                //  2. length <= 2 (only need to check endpoint) OR the inner substring is palindrome
                isPali[left][right] = (s[left] == s[right] && (len <= 2 || isPali[left + 1][right - 1]));
            }
        }

        vector<string> curr;
        vector<vector<string>> res;
        dfs(s, isPali, 0, curr, res);
        return res;
    }

private:
    void dfs(const string& s, const vector<vector<bool>> &isPali, const int left, vector<string>& curr, vector<vector<string>>& res) {
        if (left >= s.length()) {
            res.push_back(curr);
            return;
        }

        for (int right = left; right < s.length(); ++right) {
            if (isPali[left][right]) {
                curr.push_back(s.substr(left, right - left + 1));
                // Since s[left ... right] is a palindrome, we can partition it into
                // s[left ... right] + s[right + 1 ...]
                // Run dfs for the next partition
                dfs(s, isPali, right + 1, curr, res);
                curr.pop_back();
            }
        }
    }
};
