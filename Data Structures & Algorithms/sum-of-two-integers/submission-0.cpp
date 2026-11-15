class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            // a & b only preserves bits that are both zero
            // And we want to do XOR later, 1 ^ 1 = 0
            // carry will be in next position on the left (<< 1)
            int carry = (a & b) << 1;
            // 1 ^ 0 = 1, 0 ^ 1 = 1 -> sum by ignoring carry
            a ^= b;
            b = carry;
        }

        return a;
    }
};
