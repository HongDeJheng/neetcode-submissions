class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int len = s.length();
        unordered_map<char, int> lastSeenIdx;
        for (int idx = 0; idx < len; ++idx) {
            lastSeenIdx[s[idx]] = idx;
        }

        vector<int> substringLengths;
        int curLen = 0, right = 0;

        for (int left = 0; left < len; ++left) {
            ++curLen;
            right = max(right, lastSeenIdx[s[left]]);

            if (left == right) {
                substringLengths.push_back(curLen);
                curLen = 0;
            }
        }

        return substringLengths;
    }
};
