class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path; 

        backtrack(result, path, s, 0);

        return result; 
    }

    void backtrack(vector<vector<string>> &result, vector<string> &path, 
                   const string &s, int start) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            string sub = s.substr(start, i - start + 1);
            if (isPalindrome(sub)) {
                path.push_back(sub);
                backtrack(result, path, s, i + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};
