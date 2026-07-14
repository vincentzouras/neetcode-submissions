class Solution {
public:
    int dfs(vector<vector<int>> &memo, string &text1, string &text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        if (text1[i] == text2[j]) {
            memo[i][j] = dfs(memo, text1, text2, i+1, j+1) + 1;
            return memo[i][j];
        }

        memo[i][j] = max(dfs(memo, text1, text2, i+1, j),
                         dfs(memo, text1, text2, i, j+1));
        
        return memo[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
        return dfs(memo, text1, text2, 0, 0);
    }
};
