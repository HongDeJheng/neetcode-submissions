class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> res(n - k + 1);
        deque<int> dq;

        int l = 0, r = 0;
        while (r < n) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            // Out of window size: left pointer (index) is larger than the min index in dq
            if (l > dq.front()) {
                dq.pop_front();
            }

            // Start recording max num after right pointer is larger than window size
            if (r + 1 >= k) {
                res[l++] = nums[dq.front()];
            }

            ++r;
        }

        return res;
    }
};
