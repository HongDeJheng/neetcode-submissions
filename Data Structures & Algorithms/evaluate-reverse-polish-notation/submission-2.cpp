class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;

        for (auto &token : tokens) {
            if (token.length() > 1 || isdigit(token.front())) {
                num.push(stoi(token));
                continue;
            }

            auto op = token.front();
            int b = num.top();
            num.pop();
            int a = num.top();
            num.pop();
            num.push(ops.at(op)(a, b));
        }

        return num.top();
    }

private:
    // using Ops = function<int(int, int)>;
    using Ops = int(*)(int, int);
    const unordered_map<char, Ops> ops = {
        {'+', [](int a, int b){return a + b;}},
        {'-', [](int a, int b){return a - b;}},
        {'*', [](int a, int b){return a * b;}},
        {'/', [](int a, int b){return a / b;}}
    };
};
