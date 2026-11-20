class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }

        vector<string> res;
        dfs(digits, 0, "", res);
        return res;
    }

private:
    const unordered_map<char, string> digitToAlpha = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void dfs(const string& digits, const int idx, string curr, vector<string>& res) {
        if (idx == digits.size()) {
            res.emplace_back(curr);
            return;
        }

        for (auto c : digitToAlpha.at(digits[idx])) {
            dfs(digits, idx + 1, curr + c, res);
        }
    }
};
