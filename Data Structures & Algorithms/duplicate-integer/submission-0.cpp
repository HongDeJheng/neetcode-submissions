#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;

        for (auto num : nums) {
            ++count[num];

            if (count[num] > 1) {
                return true;
            }
        }

        return false;
    }
};