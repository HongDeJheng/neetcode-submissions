class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return {l + 1, r + 1};
            }
            else if (sum < target) {
                do {
                    ++l;
                } while (l < n && numbers[l] == numbers[l - 1]);
            }
            else {
                do {
                    --r;
                } while (r >= 0 && numbers[r] == numbers[r + 1]);
            }
        }

        return {-1, -1};
    }
};
