class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        unordered_map<int, int> freq;
        vector<int> nums;
        for (int candidate : candidates) {
            if (freq[candidate]++ == 0) nums.push_back(candidate);
        }

        backtrack(result, path, nums, freq, target, 0);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path, vector<int> &nums,
                   unordered_map<int, int> &freq, int remaining, int i) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        if (i == nums.size() || remaining < 0) return;

        // take
        if (freq[nums[i]] > 0) {
            path.push_back(nums[i]);
            freq[nums[i]]--;
            backtrack(result, path, nums, freq, remaining - nums[i], i);
            path.pop_back();
            freq[nums[i]]++;
        }

        // skip
        backtrack(result, path, nums, freq, remaining, i+1);
    }
};
