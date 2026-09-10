/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized = "";
        dfs(root, serialized);
        return serialized;
    }

    void dfs(TreeNode* root, string &serialized) {
        if (!root) {
            serialized += "n#"; 
            return; 
        }

        serialized += to_string(root->val) + "#";

        dfs(root->left, serialized);
        dfs(root->right, serialized);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return dfs2(data, i);
    }

    TreeNode* dfs2(string &data, int &i) {
        if (i >= data.size()) return nullptr;

        if (data[i] == 'n') {
            i += 2;
            return nullptr;
        }
        
        string value = "";
        while (data[i] != '#') {
            value += data[i++];
        }
        i++;

        TreeNode* root = new TreeNode(stoi(value));

        root->left = dfs2(data, i);
        root->right = dfs2(data, i);

        return root;
    }
};
