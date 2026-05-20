class WordDictionary {
private:
    struct Node {
        bool complete = false;
        Node* children[26] = {};
    };
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char c : word) { 
            if (!curr->children[c - 'a']) {
                Node* node = new Node();
                curr->children[c - 'a'] = node;
            }

            curr = curr->children[c - 'a'];
        }
        curr->complete = true;
    }

    bool search(string& word, int i, Node* curr) {
        for (; i < word.size(); i++) {
            char c = word[i];

            if (c == '.') {
                bool match = false;
                for (int j = 0; j < 26; j++) {
                    if (curr->children[j] && search(word, i + 1, curr->children[j])) {
                        match = true;
                        break;
                    }
                }

                return match;
            }

            if (!curr->children[c - 'a']) {
                return false;
            }

            curr = curr->children[c - 'a'];
        }

        if (!curr->complete) return false;

        return true;
    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
};
