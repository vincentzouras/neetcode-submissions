class Solution {
public:
    int dfs(string &s, vector<int> &memo, int i) {
        // base case: if we reach end of string, valid way to decode
        if (i == s.size()) return 1;
        if (memo[i] != -1) return memo[i];

        // first digit can never be zero
        if (s[i] == '0') return memo[i] = 0;

        // take one digit
        int ways = dfs(s, memo, i+1);

        // take two digits
        if (i + 1 < s.size()) {
            int num = (s[i]-'0') * 10 + (s[i+1]-'0');
            if (num <= 26)
                ways += dfs(s, memo, i+2);
        }
        
        return memo[i] = ways;
    }
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return dfs(s, memo, 0); // starting at position i, how many ways to decode
    }
};
