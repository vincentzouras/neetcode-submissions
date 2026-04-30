class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> triplets; 
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // skip duplicate i vals
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];

                if (sum == target) { // found triple
                    triplets.push_back({nums[i], nums[j], nums[k]});

                    // skip duplicates
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    
                    // still need to increment pointers
                    j++;
                    k--;
                } else if (sum < target) { // increase sum
                    j++;
                } else if (sum > target) { // decrease sum
                    k--;
                }
            }
        }

        return triplets;
    }
};
