class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> index;
        int len = 0;
        int curLeft = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (index.count(s[i])) {
                curLeft = max(curLeft, index[s[i]] + 1);
            }

            len = max(len, i - curLeft + 1);
            index[s[i]] = i;
        }

        return len;
    }
};
