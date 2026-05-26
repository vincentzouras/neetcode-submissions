class Solution {
public:
    struct Node {
        string complete = "";
        Node* children[26] = {};
    };
    Node* root = new Node();

    void insertWord(string word) {
        Node* curr = root; 
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                Node* node = new Node();
                curr->children[c - 'a'] = node;
            }
            curr = curr->children[c - 'a'];
        }
        curr->complete = word;
    }

    void dfs(vector<vector<char>>& board, 
             vector<vector<bool>>& visited, 
             vector<string>& found_words, 
             Node* curr, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (visited[r][c]) return;
        if (!curr) return;
        visited[r][c] = true;
        if (curr->complete != "") {
            found_words.push_back(curr->complete); 
            curr->complete = "";
        }
        if (c+1 < board[0].size())
            dfs(board, visited, found_words, curr->children[board[r][c+1] - 'a'], r, c+1);
        if (c-1 >= 0)
            dfs(board, visited, found_words, curr->children[board[r][c-1] - 'a'], r, c-1);
        if (r+1 < board.size())
            dfs(board, visited, found_words, curr->children[board[r+1][c] - 'a'], r+1, c);
        if (r-1 >= 0)
            dfs(board, visited, found_words, curr->children[board[r-1][c] - 'a'], r-1, c);

        visited[r][c] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string word : words) {
            insertWord(word);
        }

        vector<string> found_words;

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++){
                if (!root->children[board[r][c] - 'a']) continue;
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                dfs(board, visited, found_words, root->children[board[r][c] - 'a'], r, c);
            }
        }

        return found_words;
    }
};
