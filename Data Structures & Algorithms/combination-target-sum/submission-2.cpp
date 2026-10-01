class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> path;

        backtrack(result, path, nums, target, 0);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path, 
                   const vector<int> &nums, int remaining, int start) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        if (remaining < 0) return;

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(result, path, nums, remaining - nums[i], i);
            path.pop_back();
        }
    }
};
