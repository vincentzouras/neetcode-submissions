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
    int j = 0;
    int answer;
    void dfs(TreeNode* root, int k) {
        if (!root) return;

        dfs(root->left, k);

        j++;
        if (j == k) answer = root->val;

        dfs(root->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return answer;
    }
};
