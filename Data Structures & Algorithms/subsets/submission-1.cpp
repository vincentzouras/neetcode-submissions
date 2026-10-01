class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path; 

        backtrack(result, path, nums, 0);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path, 
                   const vector<int> &nums, int start) {        
        result.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(result, path, nums, i + 1);
            path.pop_back();
        }
    }
};
