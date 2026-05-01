class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int> freqs(26, 0);
        int l = 0;
        int max_freq = 0;
        int max_window = 0;
        for (int r = 0; r < n; r++) {
            // increment freq 
            freqs[s[r] - 'A']++;

            // update running max
            max_freq = max(max_freq, freqs[s[r] - 'A']);

            // check if exceeding k replacement threshold 
            // size of window - char we have most of = needed replacements
            while ((r - l + 1) - max_freq > k) { 
                freqs[s[l] - 'A']--;
                l++;
            }

            // update answer
            max_window = max(max_window, (r - l + 1));
        }

        return max_window;
    }
};
