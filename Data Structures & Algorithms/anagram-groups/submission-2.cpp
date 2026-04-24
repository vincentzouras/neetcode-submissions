class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // group strings by char counts
        unordered_map<string, vector<string>> groups;
        for (const string &str : strs) { 
            vector<int> freqs(26, 0); 
            for (const char &c : str) {
                freqs[c - 'a']++;
            }
            string key = make_key(freqs);
            groups[key].push_back(str);
        }

        // build result list from map values
        vector<vector<string>> anagrams;
        for (const auto &[_, value] : groups) {
            anagrams.push_back(value);
        }
        
        return anagrams;

        /*
        solution becomes O(n k) compared to the sorting method which was O(n k log k)

        for each string, instead of sorting, we iterate over its size k once to get its freqs
        */
    }
private: 
    // helper function to convert the vector of ints to a hashable string for the map
    string make_key(const vector<int> &freqs) {
        string result;
        for (int i = 0; i < freqs.size(); i++) { 
            result += (char) (i + 'a');
            result += to_string(freqs[i]);
            result += '#';
        }
        return result;
    }
};
