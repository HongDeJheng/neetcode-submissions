class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, 0, 0, "", res);
        return res;
    }

private:
    void generate(const int& n, const int openCnt, const int closeCnt, string current, vector<string>& res) {
        if (openCnt == n && closeCnt == n) {
            res.emplace_back(current);
            return;
        }

        if (openCnt < n) {
            generate(n, openCnt + 1, closeCnt, current + "(", res);
        }

        if (closeCnt < openCnt) {
            generate(n, openCnt, closeCnt + 1, current + ")", res);
        }
    }
};
