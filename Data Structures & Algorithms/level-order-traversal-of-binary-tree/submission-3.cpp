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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 

        dfs(root, result, 0);

        return result;
    }

    void dfs(TreeNode* root, vector<vector<int>> &result, int depth) {
        if (!root) return;

        if (result.size() <= depth) result.push_back({});

        result[depth].push_back(root->val);

        dfs(root->left, result, depth + 1);
        dfs(root->right, result, depth + 1);
    }
};
