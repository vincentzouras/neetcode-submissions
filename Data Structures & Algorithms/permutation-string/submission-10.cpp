class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) return false;

        unordered_map<char, int> counts; // difference between s1 and window count
        int matches = 0;
        int need = 0;

        for (char c : s1) {
            counts[c]++;
            if (counts[c] == 1) need++;
        }

        int r = 0;
        for (; r < m; r++) {
            char curr = s2[r];
            if (counts.contains(curr)) {
                counts[curr]--;
                if (counts[curr] == 0) {
                    matches++;
                }
                if (matches == need) return true;
            }
        }

        for (int l = 0; r < n; l++) {
            char right = s2[r];
            char left = s2[l];
            
            if (counts.contains(right)) {
                counts[right]--;
                if (counts[right] == 0) matches++;
            }

            if (counts.contains(left)) {
                if (counts[left] == 0) matches--;
                counts[left]++;
            }

            if (matches == need) return true;

            r++;
        }

        return false;
    }
};
