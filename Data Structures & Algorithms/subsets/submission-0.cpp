class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> path; 

        backtrack(subsets, path, nums, 0);

        return subsets; 
    }

    void backtrack(vector<vector<int>> &subsets, 
                   vector<int> &path,
                   vector<int> &nums,
                   int i) {
        if (i >= nums.size()) {
            subsets.push_back(path); 
            return;
        }

        // take num
        path.push_back(nums[i]);
        backtrack(subsets, path, nums, i + 1);
        path.pop_back();

        // dont take num
        backtrack(subsets, path, nums, i + 1);
    }
};
