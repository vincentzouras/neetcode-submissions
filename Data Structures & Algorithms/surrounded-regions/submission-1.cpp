class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // preserve
        for (int r = 0; r < m; r++) {
            dfs(board, r, 0);
            dfs(board, r, n-1);
        }
        for (int c = 0; c < n; c++) {
            dfs(board, 0, c);
            dfs(board, m-1, c);            
        }

        // surround
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
            }
        }

        // restore
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'K') board[r][c] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (board[r][c] != 'O') return;

        board[r][c] = 'K';

        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
};
