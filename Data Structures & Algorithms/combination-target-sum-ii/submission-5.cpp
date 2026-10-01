class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        backtrack(result, path, candidates, target, 0);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path, vector<int> &cands, 
                   int remaining, int start) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        if (remaining < 0) return;

        for (int i = start; i < cands.size(); i++) {
            if (i > start && cands[i] == cands[i-1]) continue;
            path.push_back(cands[i]);
            backtrack(result, path, cands, remaining - cands[i], i + 1);
            path.pop_back();
        }

    }
};
