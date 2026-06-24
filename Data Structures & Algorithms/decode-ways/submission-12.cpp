class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        /*
        Two choices:
         - parse curr char by itself
         - parse prev char and curr char together
        */

        if (s[0] == '0') return 0;

        int prev = 1;
        int prev_prev = 1;

        for (int i = 1; i < n; i++) {
            int curr = 0;

            if (s[i] != '0') {
                curr += prev;
            }

            int num = (s[i-1] - '0') * 10 + s[i] - '0';
            if (num >= 10 && num <= 26) {
                curr += prev_prev;
            }

            prev_prev = prev;
            prev = curr;
        }

        return prev;
    }
};
