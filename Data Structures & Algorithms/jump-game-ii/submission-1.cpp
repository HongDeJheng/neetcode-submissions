class Solution {
public:
    int jump(vector<int>& nums) {
        const int dest = nums.size() - 1;
        int count = 0;
        int left = 0, right = 0;

        while (right < dest) {
            int farthest = 0;
            for (int idx = left; idx <= right; ++idx) {
                farthest = max(farthest, idx + nums[idx]);
            }

            left = right + 1;
            right = farthest;
            ++count;
        }

        return count;
    }
};
