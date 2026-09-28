class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> path;

        backtrack(result, path, nums, target, 0); 

        return result; 
    }

    void backtrack(vector<vector<int>> &result, 
                   vector<int> &path, const vector<int> &nums, 
                   int remaining, int i) {
        if (i == nums.size() || remaining < 0) return;
        if (remaining == 0) {
            result.push_back(path);
            return;
        }

        // take and stay
        path.push_back(nums[i]);
        backtrack(result, path, nums, remaining - nums[i], i);
        path.pop_back();

        // skip
        backtrack(result, path, nums, remaining, i + 1);
   }
};
