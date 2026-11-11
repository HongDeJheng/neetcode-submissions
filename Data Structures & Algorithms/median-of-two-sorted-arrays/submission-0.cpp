class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        const int half = (m + n + 1) / 2;
        int l = 0, r = m;
        while (l <= r) {
            int mid1 = (l + r) / 2;
            int mid2 = half - mid1;

            int left1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
            int right1 = mid1 < m ? nums1[mid1] : INT_MAX;

            int left2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
            int right2 = mid2 < n ? nums2[mid2] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 != 0) {
                    return max(left1, left2);
                }

                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else if (left1 > right2) {
                r = mid1 - 1;
            }
            else {
                l = mid1 + 1;
            }
        }

        return -1;
    }
};
