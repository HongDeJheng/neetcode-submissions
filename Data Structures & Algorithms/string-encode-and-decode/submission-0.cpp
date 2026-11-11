class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "$" + to_string(strs.size());
        for (auto str : strs) {
            encoded += "$" + to_string(str.length()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        auto sizeIdx = s.find("$", 1);
        int size = stoi(s.substr(1, sizeIdx - 1));
        vector<string> res(size);

        for (int i = 0; i < size; ++i) {
            auto strIdx = s.find("#", sizeIdx);
            auto strSize = stoi(s.substr(sizeIdx + 1, strIdx - sizeIdx));
            sizeIdx = strIdx + strSize + 1;
            res[i] = s.substr(strIdx + 1, strSize);
        }

        return res;
    }
};
