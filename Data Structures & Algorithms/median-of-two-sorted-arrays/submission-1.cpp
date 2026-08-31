class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int left = 0;
        int right = m;
        int half = (m + n + 1) / 2;

        while (left <= right) {
            int mid1 = left + (right - left) / 2;
            int mid2 = half - mid1;

            int left1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int right1 = (mid1 == m) ? INT_MAX : nums1[mid1];

            int left2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int right2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if (left1 <= right2 && right1 >= left2) {
                if ((m + n) % 2 == 1) return max(left1, left2);
                int largestLeft = max(left1, left2);
                int smallestRight = min(right1, right2);

                return (largestLeft + smallestRight) / 2.0;

            } else if (left1 > right2) right = mid1 - 1;

            else left = mid1 + 1;
        }

        return 0.0;
    }
};
