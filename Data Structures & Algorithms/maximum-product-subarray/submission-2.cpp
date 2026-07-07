class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prev_max = nums[0];
        int prev_min = nums[0];
        int global_max = nums[0];

        for (int i = 1; i < n; i++) {
            int temp = prev_max;
            prev_max = max(nums[i], max(prev_max * nums[i], prev_min * nums[i]));
            prev_min = min(nums[i], min(prev_min * nums[i], temp * nums[i]));
            global_max = max(global_max, prev_max);
        }

        return global_max;
    }
};
