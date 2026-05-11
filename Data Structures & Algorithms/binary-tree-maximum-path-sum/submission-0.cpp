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
    int max_path_sum = INT_MIN; 
    int pathSum(TreeNode* root) {
        if (!root) return 0; 

        int sum_left = pathSum(root->left);
        int sum_right = pathSum(root->right);

        // What is the best path at this node?
        // 1. Node alone
        // 2. Node + left
        // 3. Node + right
        // 4. Node + left + right
        max_path_sum = max({max_path_sum,
                            root->val, 
                            root->val + sum_left, 
                            root->val + sum_right, 
                            root->val + sum_left + sum_right});
        
        // Pass up the max that a parent could use
        // - A parent can only use one side
        return max({root->val, 
                    root->val + sum_left, 
                    root->val + sum_right});
    }
    int maxPathSum(TreeNode* root) {
        pathSum(root);
        return max_path_sum;
    }
};
