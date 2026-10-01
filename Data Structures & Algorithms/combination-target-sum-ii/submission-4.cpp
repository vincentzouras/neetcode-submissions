class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        unordered_map<int, int> freq;
        vector<int> uniques;
        for (int candidate : candidates) {
            if (freq[candidate]++ == 0) uniques.push_back(candidate);
        }

        backtrack(result, path, freq, uniques, target, 0);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path, 
                   unordered_map<int, int> &freq, const vector<int> &uniques, 
                   int remaining, int start) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        if (remaining < 0) return;

        for (int i = start; i < uniques.size(); i++) {
            if (freq[uniques[i]] > 0) {
                freq[uniques[i]]--;
                path.push_back(uniques[i]);
                backtrack(result, path, freq, uniques, remaining - uniques[i], i);
                freq[uniques[i]]++;
                path.pop_back();
            }
        }
    }
};
