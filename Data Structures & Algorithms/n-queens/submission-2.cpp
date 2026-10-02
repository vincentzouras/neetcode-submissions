class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result; 
        vector<string> path;

        backtrack(result, path, n, 0);


        return result;
    }

    void backtrack(vector<vector<string>> &result, vector<string> &path,
                   int n, int currRow) {
        if (currRow == n) {
            result.push_back(path);
            return;
        }

        // consider each of n new row options 
        for (int c = 0; c < n; c++) {

            if (isValid(path, currRow, c)) {
                string s = "";
                for (int i = 0; i < n; i++) {
                    if (c == i) s.push_back('Q');
                    else s.push_back('.');
                }

                path.push_back(s);
                backtrack(result, path, n, currRow + 1);
                path.pop_back();
            }
        }
    }

    bool isValid(vector<string> &path, int r, int c) {
        // can I add this string to the current path? 
        for (int row = 0; row < path.size(); row++) {
            for (int col = 0; col < path[0].size(); col++){
                if (path[row][col] == 'Q' && 
                   (r == row || c == col || abs(row - r) == abs(col - c))) return false;
            }
        }
        return true;
    }
};
