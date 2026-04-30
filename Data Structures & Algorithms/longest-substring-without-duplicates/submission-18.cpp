class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> window_chars;
        int longest = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            while (window_chars.contains(s[r])) {
                window_chars.erase(s[l]);
                l++;
            }
            window_chars.insert(s[r]);
            longest = max(longest, (int)window_chars.size());
        }

        return longest;
    }
};
