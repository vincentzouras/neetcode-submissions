class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        vector<unordered_set<char>> rowSet(n);
        vector<unordered_set<char>> colSet(n);
        vector<unordered_set<char>> boxSet(n);
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                char curr = board[r][c];
                if (curr == '.') continue;

                // check row
                if (rowSet[r].contains(curr)) return false;
                rowSet[r].insert(curr);

                // check col
                if (colSet[c].contains(curr)) return false;
                colSet[c].insert(curr);

                // check box
                int box = (r/3) * 3 + (c/3); // get box row, shift by 3, add box col
                if (boxSet[box].contains(curr)) return false;
                boxSet[box].insert(curr);
            }
        }

        return true;
    }
};
