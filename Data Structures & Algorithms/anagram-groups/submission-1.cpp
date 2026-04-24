class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // group strings by sorted key
        unordered_map<string, vector<string>> groups;
        for (const string &str : strs) { 
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end()); 
            groups[sorted_str].push_back(str); 
        }

        // build result list from map values
        vector<vector<string>> anagrams; 
        for (const auto &[_, group] : groups) {
            anagrams.push_back(group);
        }

        return anagrams;

        /*
        sorting each string: O(k log k)
        for n total strings: O(n k log k)
        */
    }
};
