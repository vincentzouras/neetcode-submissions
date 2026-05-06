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
    bool isValidBST(TreeNode* root, int lower, int upper) {
        if (!root) return true;

        if (root->val >= upper || root->val <= lower)
            return false;

        return isValidBST(root->left, lower, min(upper, root->val)) && 
               isValidBST(root->right, max(lower, root->val), upper);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, -1001, 1001);
    }
};
