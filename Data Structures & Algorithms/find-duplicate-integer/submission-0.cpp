class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slowPtr = nums.front();
        int fastPtr = nums.front();

        do {
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        } while (slowPtr != fastPtr);

        // slowPtr walks d_s = L + X
        // fastPtr walks d_f = L + n * C + X
        // where L = distance to entrance of cycle from the beginning
        //       C = distance of cycle
        //       X = extra distance walked
        // And d_f = d_s * 2
        // => 2L + 2X = L + X + n * C
        // => L + X = n * C
        // => L = nC - X = (n - 1)C + (C - X)
        // Where C - X is the distance of fastPtr to the entrace of cycle
        // Since C is just walking the cycle, we can ignore it
        // => L = C - X
        // => distance to entrace of cycle from the beginning = fastPtr's distance to entrance of cylce
        // => Let slowPtr walk from start, and fastPtr at the current position
        //    They will meet at entrance after distance (L = C - X)
        slowPtr = nums.front();
        while (slowPtr != fastPtr) {
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }

        return slowPtr;
    }
};
