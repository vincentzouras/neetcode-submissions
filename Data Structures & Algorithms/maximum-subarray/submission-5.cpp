class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;

        int currSum = 0;
        for (int i = 0; i < n; i++) {
            if (currSum < 0) currSum = 0;
            currSum += nums[i];

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
