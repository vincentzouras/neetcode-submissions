class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> zero_rows;
        unordered_set<int> zero_cols;        

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == 0) {
                    zero_rows.insert(r);
                    zero_cols.insert(c);
                }
            }
        }

        for (int r : zero_rows) {
            for (int &el : matrix[r]) {
                el = 0;
            }
        }

        for (int c : zero_cols) {
            for (vector<int> &row : matrix) {
                row[c] = 0;
            }
        }
    }
};
