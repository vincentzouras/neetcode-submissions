class PrefixTree {
private: 
    struct Node {
        char val; 
        bool complete;
        vector<Node*> children;
        Node() : val(' '), complete(false) {}
        Node(char v) : val(v), complete(false) {}
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
            bool exists = false;
            int j = 0;

            for (; j < curr->children.size(); j++) {
                Node* child = curr->children[j];
                if (child->val == c) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                curr = curr->children[j];
            } else {
                Node* node = new Node(c);
                curr->children.push_back(node);
                curr = curr->children.back();
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
            bool exists = false;
            int j = 0;

            for (; j < curr->children.size(); j++) {
                Node* child = curr->children[j];
                if (child->val == c) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                curr = curr->children[j];
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
            bool exists = false;
            int j = 0;

            for (; j < curr->children.size(); j++) {
                Node* child = curr->children[j];
                if (child->val == c) {
                    exists = true;
                    break;
                }
            }

            if (exists) {
                curr = curr->children[j];
            } else {
                return false;
            }
        }

        return true;
    }
};
