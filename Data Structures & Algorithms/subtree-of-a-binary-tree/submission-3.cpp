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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        else if (!a || !b) return false;
        else if (a->val != b->val) return false;

        bool leftMatches = isSameTree(a->left, b->left);
        bool rightMatches = isSameTree(a->right, b->right);

        return leftMatches && rightMatches;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;

        bool checkLeft = isSubtree(root->left, subRoot);
        bool checkRight = isSubtree(root->right, subRoot);

        return checkLeft || checkRight;
    }
};
