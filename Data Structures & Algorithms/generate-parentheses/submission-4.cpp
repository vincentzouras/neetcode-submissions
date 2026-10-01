class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;

        backtrack(result, path, 0, 0, n);

        return result;
    }

    void backtrack(vector<string> &result, string &path, int numOpen, int numClosed, int n) {
        if (path.size() == n * 2) {
            result.push_back(path);
            return;
        }

        if (numOpen < n) {
            path.push_back('(');
            backtrack(result, path, numOpen + 1, numClosed, n);
            path.pop_back();
        }

        if (numClosed < numOpen) {
            path.push_back(')');
            backtrack(result, path, numOpen, numClosed + 1, n);
            path.pop_back();
        }

    }
};
