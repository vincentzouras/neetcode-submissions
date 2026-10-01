class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;

        backtrack(result, path, 0, 0, n);

        return result;
    }

    void backtrack(vector<string> &result, string &path, int numOpen, int numClosed, int n) {
        if (path.size() == n * 2 && numOpen == numClosed) {
            result.push_back(path);
            return;
        }
        if (path.size() > n*2) return;
        if (numClosed > numOpen) return;

        path.push_back('(');
        backtrack(result, path, numOpen + 1, numClosed, n);
        path.pop_back();

        path.push_back(')');
        backtrack(result, path, numOpen, numClosed + 1, n);
        path.pop_back();
    }
};
