class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result; 
        vector<int> path;

        sort(candidates.begin(), candidates.end());
        
        backtrack(result, path, candidates, target, 0);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path, 
                   const vector<int> &candidates, int remaining, int i) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        if (i == candidates.size() || remaining < 0) return;

        // take and advance
        path.push_back(candidates[i]);
        backtrack(result, path, candidates, remaining - candidates[i], i + 1);
        path.pop_back();

        // skip and advance, be sure to skip duplicates
        i++;
        while (i < candidates.size() && candidates[i] == candidates[i - 1]) i++;
        backtrack(result, path, candidates, remaining, i);
    }
};
