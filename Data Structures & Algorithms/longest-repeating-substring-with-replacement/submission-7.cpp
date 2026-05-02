class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freqs(26, 0);

        int longest_window = 0; 
        int max_freq = 0; 
        int l = 0;
        for (int r = 0; r < n; r++) { 
            freqs[s[r] - 'A']++;
            max_freq = max(max_freq, freqs[s[r] - 'A']);
            while ((r - l + 1) - max_freq > k) {
                freqs[s[l++] - 'A']--;
                // No need to update max_freq since any stale
                // values that reach longest_window are guaranteed
                // to be smaller than a window we had before.
            }
            longest_window = max(longest_window, (r - l + 1));
        }

        return longest_window;
    }
};
