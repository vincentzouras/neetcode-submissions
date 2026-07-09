class Solution {
public:
    bool dfs(int i, string &s, vector<string>& wordDict, vector<int> &memo) {
        if (i == s.size()) return true;
        if (memo[i] != -1) return memo[i];

        for (string word : wordDict) {
            if (s.size() - i < word.size()) continue;

            // does word match start of s
            bool match = true;
            for (int j = 0; j < word.size(); j++) {
                if (s[j + i] != word[j]) {
                    match = false;
                    break;
                }
            }

            // yes
            if (match) {
                if (dfs(i + word.size(), s, wordDict, memo)) {
                    memo[i] = 1;
                    return true;
                }
            }
        }

        memo[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1); 
        return dfs(0, s, wordDict, memo);
    }
};
