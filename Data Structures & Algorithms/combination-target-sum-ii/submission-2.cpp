class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;

        unordered_map<int, int> freq;
        for (int candidate : candidates) {
            freq[candidate]++;
        }

        backtrack(result, path, freq, target, 0);

        return result;
    }

    void backtrack(vector<vector<int>> &result, vector<int> &path,
                   unordered_map<int, int> &freq, int remaining, int i) {
        if (remaining == 0) {
            result.push_back(path);
            return;
        }
        if (i == freq.size() || remaining < 0) return;

        // take
        if (freq[i] > 0) {
            path.push_back(i);
            freq[i]--;
            backtrack(result, path, freq, remaining - i, i);
            path.pop_back();
            freq[i]++;
        }

        // skip
        backtrack(result, path, freq, remaining, i+1);
    }
};
