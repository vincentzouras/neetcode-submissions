class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;

        int max_len = 0;
        int start_i = 0;

        for (int i = 0; i < n; i++) {
            // odd length expansion
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > max_len) {
                    max_len = right - left + 1;
                    start_i = left;
                }
                left--;
                right++;
            }

            // even length expansion
            left = i; 
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > max_len) {
                    max_len = right - left + 1;
                    start_i = left;
                }
                left--;
                right++;
            } 
        }

        return s.substr(start_i, max_len);
    }
};
