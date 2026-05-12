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
    void dfs_s(TreeNode* node, string& result) {
        if (!node) {
            result += "null ";
            return;
        }

        result += to_string(node->val) + " ";

        dfs_s(node->left, result);
        dfs_s(node->right, result);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        dfs_s(root, result);
        return result;
    }

    TreeNode* dfs_d(stringstream& ss) {
        string val;
        ss >> val;

        if (val == "null") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));

        node->left = dfs_d(ss);
        node->right = dfs_d(ss);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dfs_d(ss);
    }
};
