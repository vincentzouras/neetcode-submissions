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
             vector<string>& found_words, 
             Node* curr, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (board[r][c] == '#') return;

        curr = curr->children[board[r][c] - 'a'];
        if (!curr) return;

        if (curr->complete != "") {
            found_words.push_back(curr->complete); 
            curr->complete = "";
        }
        
        char temp = board[r][c];
        board[r][c] = '#';
        
        dfs(board, found_words, curr, r, c+1);
        dfs(board, found_words, curr, r, c-1);
        dfs(board, found_words, curr, r+1, c);
        dfs(board, found_words, curr, r-1, c);

        board[r][c] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string word : words) {
            insertWord(word);
        }

        vector<string> found_words;

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++){
                if (!root->children[board[r][c] - 'a']) continue;
                dfs(board, found_words, root, r, c);
            }
        }

        return found_words;
    }
};
