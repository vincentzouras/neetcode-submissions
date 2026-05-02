class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        vector<int> need(128);
        int required = 0;
        for (char c : t) {
            need[c]++;
            if (need[c] == 1) required++; // increment for distinct
        }
        
        vector<int> have(128);
        int formed = 0;

        string shortest_substring = "";
        int l = 0;
        int r = 0;
        for (; r < n; r++) {
            // add to window
            have[s[r]]++; 

            // update formed if we need it and just got enough of it
            if (need[s[r]] > 0 && have[s[r]] == need[s[r]]) formed++;

            // try shrinking l while we have valid window
            while (formed == required) {
                // update answer
                if ((r - l + 1) < shortest_substring.size() || shortest_substring.empty()) {
                    shortest_substring = s.substr(l, (r - l + 1));
                }

                // check if removing l from window breaks requirement
                char removed = s[l];
                have[s[l++]]--;
                if (have[removed] < need[removed]) formed--;
            }
        }

        return shortest_substring;
    }
};
