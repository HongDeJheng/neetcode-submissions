class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        auto getSquareSum = [](int num) {
            int squareSum = 0;
            while (num) {
                int digit = num % 10;
                squareSum += digit * digit;
                num /= 10;
            }
            return squareSum;
        };

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getSquareSum(n);
        }

        return n == 1;
    }
};
