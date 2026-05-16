class Solution {
public:
    void backtrack(vector<int> &nums, 
                   vector<vector<int>> &combinations, 
                   vector<int> &combo, 
                   int i, 
                   int remaining) {
        if (remaining == 0) {
            combinations.push_back(combo);
            return;
        }

        for (; i < nums.size(); i++) {
            if (nums[i] <= remaining){ 
                combo.push_back(nums[i]);
                backtrack(nums, combinations, combo, i, remaining - nums[i]);
                combo.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> combinations;
        vector<int> combo;
        backtrack(nums, combinations, combo, 0, target);
        return combinations;
    }
};
