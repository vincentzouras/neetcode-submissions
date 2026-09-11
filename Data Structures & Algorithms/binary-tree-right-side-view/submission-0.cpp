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
    vector<vector<int>> levels;
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        dfs(root, 0);

        vector<int> result;
        for (vector<int> level : levels) {
            result.push_back(level.back());
        }

        return result;
    }

    void dfs(TreeNode* root, int height) {
        if (!root) return;

        if (height >= levels.size()) levels.push_back({});
        levels[height].push_back(root->val);

        dfs(root->left, height + 1);
        dfs(root->right, height + 1);
    }
};
