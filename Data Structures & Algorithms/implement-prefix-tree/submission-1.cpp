class PrefixTree {
private: 
    struct Node {
        bool complete = false;
        Node* children[26] = {};
    };

    Node* root;
public:
    PrefixTree() {
        root = new Node(); 
    }
    
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (curr->children[c - 'a']) {
                curr = curr->children[c - 'a'];
            } else {
                Node* node = new Node();
                curr->children[c - 'a'] = node;
                curr = curr->children[c - 'a'];
            }

            if (i == word.size() - 1) {
                curr->complete = true;
            }
        }
    }
    
    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (curr->children[c - 'a']) {
                curr = curr->children[c - 'a'];
            } else {
                return false;
            }

            if (i == word.size() - 1) {
                if (!curr->complete) return false;
            }
        }

        return true;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];

            if (curr->children[c - 'a']) {
                curr = curr->children[c - 'a'];
            } else {
                return false;
            }
        }

        return true;
    }

    /*
    Instead of storing a value and a vector of children, we can use an array of 26 nodes
    where the existence of a node at an index indicates that letter exists

    This improves our time complexity to O(n) because it is a O(1) operation to see if 
    we have a letter in the children of a node
    */
};
