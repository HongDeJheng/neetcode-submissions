class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[l] <= nums[mid]) {
                if (target > nums[mid] || target < nums[l]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else {
                if (target < nums[mid] || target > nums[r]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};
