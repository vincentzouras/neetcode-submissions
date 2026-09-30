class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int> path;
        vector<bool> used(nums.size()); // index of used nums 

        backtrack(result, path, used, nums);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path, 
                   vector<bool> &used, vector<int> &nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(result, path, used, nums);

                used[i] = false;
                path.pop_back();
            }
        }
    }
};
