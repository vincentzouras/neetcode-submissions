class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        } // left is now at deflection point 

        // set pointers for final search
        if (left == 0) { 
            // already sorted
            right = nums.size() - 1;
        } else if (target >= nums[0]) {
            right = left - 1;
            left = 0;
        } else {
            right = nums.size() - 1;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
