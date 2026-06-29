class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1); // dp[i] = # ways to decode s[i:]
        dp[n] = 1;

        int prev = 1;
        int prevPrev = 0;

        for (int i = n-1; i >= 0; i--) { 

            int curr = 0;

            // take one digit
            if (s[i] != '0')
                curr = prev;

            // take two digits
            if (i < n-1 && s[i] != '0') {
                int num = ((s[i]-'0') * 10) + (s[i+1]-'0');
                if (num <= 26) curr += prevPrev;
            }

            prevPrev = prev;
            prev = curr;
        }

        return prev;
    }
};
