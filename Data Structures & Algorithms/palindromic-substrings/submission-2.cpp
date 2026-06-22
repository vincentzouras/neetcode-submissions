class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // length 1 substrings are always palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            count++;
        }

        // length 2 substrings are if letters match
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                count++;
            }
        }

        // length >= 3 substrings if outer letters match and inside is palindrome
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                    if (dp[i][j]) count++;
                }
            }
        }

        return count;
    }
};
