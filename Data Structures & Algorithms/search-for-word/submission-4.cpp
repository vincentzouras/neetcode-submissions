class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == word[0]) {
                    if (backtrack(board, word, 0, r, c)) return true;
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>> &board, string &word, int i, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if (board[r][c] == '#') return false;
        if (word[i] != board[r][c]) return false;
        if (i == word.size() - 1) return true;

        char store = board[r][c];
        board[r][c] = '#';

        bool found = backtrack(board, word, i+1, r+1, c) ||
                     backtrack(board, word, i+1, r-1, c) ||
                     backtrack(board, word, i+1, r, c+1) ||
                     backtrack(board, word, i+1, r, c-1);
        
        board[r][c] = store;

        return found;

    }
};
