class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        const int len1 = num1.length();
        const int len2 = num2.length();
        vector<int> reverseDigits(len1 + len2);

        for (int i = 0; i < len1; ++i) {
            char c1 = num1[len1 - i - 1];

            for (int j = 0; j < len2; ++j) {
                const int idx = i + j;
                char c2 = num2[len2 - j - 1];

                int product = (c1 - '0') * (c2 - '0');
                reverseDigits[idx] += product;
                reverseDigits[idx + 1] += reverseDigits[idx] / 10;
                reverseDigits[idx] %= 10;
            }
        }

        stringstream ss;
        int startIdx = reverseDigits.size() - 1;
        while (startIdx >= 0 && reverseDigits[startIdx] == 0) {
            --startIdx;
        }

        while (startIdx >= 0) {
            ss << reverseDigits[startIdx--];
        }

        return ss.str();
    }
};
