class Solution {
public:
    bool isValid(string s) {
        const string open = "([{";
        const unordered_map<char, char> corres = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> st;
        auto isOpen = [&](const char c){ return open.find(c) != string::npos; };

        for (auto c : s) {
            if (isOpen(c)) {
                st.push(c);
            }
            else {
                auto corresponding = corres.at(c);
                if (st.empty() || st.top() != corresponding) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};
