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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // nothing left to make the root
        if (preorder.empty()) return nullptr;

        // first node in preorder is root 
        TreeNode* root = new TreeNode(preorder[0]);

        // index of that value in inorder divides left and right subtree nodes
        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        // pre: [1][2][3,4]
        //  root left_sub right_sub

        // in: [2][1][3,4]
        //  left_sub root right_sub

        auto it = preorder.begin() + 1;
        vector<int> preorder_left(it, it + mid);
        vector<int> preorder_right(it + mid, preorder.end());

        it = inorder.begin();
        vector<int> inorder_left(it, it + mid);
        vector<int> inorder_right(it + mid + 1, inorder.end());

        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);

        return root;
    }
};
