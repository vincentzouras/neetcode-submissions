class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start_i = 0;
        int max_len = 1;

        // length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start_i = i;
                max_len = 2;
            }
        }

        // length >= 3
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    if (max_len < j - i + 1) {
                        max_len = j - i + 1;
                        start_i = i;
                    }
                }
            }
        }

        return s.substr(start_i, max_len);
    }
};
