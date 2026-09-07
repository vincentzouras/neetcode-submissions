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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        return dfs(root->left, INT_MIN, root->val) && 
               dfs(root->right, root->val, INT_MAX);
    }

    bool dfs(TreeNode* node, int lower, int upper) {
        if (!node) return true;
        if (node->val >= upper || node->val <= lower) return false;
        return dfs(node->left, lower, node->val) && 
               dfs(node->right, node->val, upper);
    }
};
