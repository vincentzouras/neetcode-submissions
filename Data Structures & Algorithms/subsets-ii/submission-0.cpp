class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;

        unordered_map<int, int> freq;
        vector<int> uniques;
        for (int num : nums) {
            if (freq[num]++ == 0) uniques.push_back(num);
        }

        backtrack(result, freq, uniques, path, 0);

        return result; 
    }

    void backtrack(vector<vector<int>> &result, unordered_map<int, int> &freq, 
                   vector<int> &uniques, vector<int> &path, int i) {
        if (i == uniques.size()) {
            result.push_back(path);
            return;
        }

        if (freq[uniques[i]] > 0) {
            freq[uniques[i]]--;
            path.push_back(uniques[i]);
            backtrack(result, freq, uniques, path, i);
            freq[uniques[i]]++;
            path.pop_back();
        }

        backtrack(result, freq, uniques, path, i + 1);
    }
};
