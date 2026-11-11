class Solution {
public:
    int findMin(vector<int> &nums) {
        const int n = nums.size();
        int l = 0, r = n - 1;
        int res = nums.front();
        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }

            int mid = (l + r) / 2;
            res = min(res, nums[mid]);

            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return res;
    }
};
