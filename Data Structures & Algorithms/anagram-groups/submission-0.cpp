class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (auto &str : strs) {
            anagrams[getHash(str)].push_back(str);
        }

        vector<vector<string>> res;
        for (auto it = anagrams.begin(); it != anagrams.end(); ++it) {
            res.emplace_back(it->second);
        }

        return res;
    }

private:
    string getHash(const string &s) {
        int cnt[26] = {0};

        for (auto c : s) {
            ++cnt[c - 'a'];
        }

        string hash;
        for (int i = 0; i < 26; ++i) {
            hash += "#" + to_string(cnt[i]);
        }

        return hash;
    }
};
