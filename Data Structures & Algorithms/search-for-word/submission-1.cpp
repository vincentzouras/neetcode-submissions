class Solution {
public:
    bool backtrack(vector<vector<char>> &board, 
                   vector<vector<bool>> &visited,
                   string &word, 
                   int r, int c, int i) {

        if (r < 0 || r > board.size() - 1 || c < 0 || c > board[0].size() - 1) return false;
        if (visited[r][c]) return false;
        if (board[r][c] != word[i]) return false;
        if (i == word.size() - 1) return true;

        visited[r][c] = true;
        
        bool present = backtrack(board, visited, word, r + 1, c, i + 1) ||
                       backtrack(board, visited, word, r - 1, c, i + 1) ||
                       backtrack(board, visited, word, r, c + 1, i + 1) ||
                       backtrack(board, visited, word, r, c - 1, i + 1);
        
        visited[r][c] = false;

        return present;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool present = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (present) return true;
                present = backtrack(board, visited, word, r, c, 0);
            }
        }

        return present;

        /*
        For each of m * n cells
        We have 4 options, after which 3 options for the remaining L-1 letters
        So O(m * n * 4 * 3^(L-1)) is the total time complexity
        Which reduces to O(m * n * 3^L)
        */
    }
};