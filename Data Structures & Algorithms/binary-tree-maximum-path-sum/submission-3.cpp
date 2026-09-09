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
    int maxPath = INT_MIN;
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return maxPath;
    }

    int pathSum(TreeNode* root) {
        if (!root) return 0;

        int left = pathSum(root->left);
        int right = pathSum(root->right);

        // Three options:
        // 1. self + L + R
        // 2. self + max(L,R)
        // 3. self

        int one = root->val + left + right;
        int two = root->val + max(left, right);
        int three = root->val;

        int best = max(one, max(two, three));

        maxPath = max(maxPath, best);

        return max(two, three);
    }
};
