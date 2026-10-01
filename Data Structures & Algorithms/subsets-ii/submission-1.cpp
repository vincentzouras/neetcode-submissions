class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        sort(nums.begin(), nums.end());

        backtrack(result, path, nums, 0);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, int start) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backtrack(result, path, nums, i + 1);
            path.pop_back();
        }
    }
};
