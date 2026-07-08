class Solution {
public:
    bool dfs(string s, vector<string>& wordDict, unordered_map<string, bool> &memo) {
        if (s == "") return true;
        if (memo.contains(s)) return memo[s];

        for (string word : wordDict) {
            if (s.size() < word.size()) continue;

            // does word match start of s
            bool match = true;
            for (int i = 0; i < word.size(); i++) {
                if (s[i] != word[i]) {
                    match = false;
                    break;
                }
            }

            // yes
            if (match) {
                if (dfs(s.substr(word.size(), s.size()), wordDict, memo)) {
                    memo[s] = true;
                    return true;
                }
            }
        }

        memo[s] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> memo; 
        return dfs(s, wordDict, memo);
    }
};
