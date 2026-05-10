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
    unordered_map<int, int> inorder_indexes;
    TreeNode* buildSubtree(const vector<int>& preorder, int pl, int pr, 
                           const vector<int>& inorder, int il, int ir) {
        if (pl > pr || il > ir) return nullptr;

        TreeNode* root = new TreeNode(preorder[pl]);

        int mid = inorder_indexes[preorder[pl]];

        int size_left = mid - il;

        root->left = buildSubtree(preorder, pl + 1, pl + size_left,
                                  inorder, il, mid - 1);
        root->right = buildSubtree(preorder, pl + size_left + 1, pr,
                                   inorder, mid + 1, ir);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_indexes[inorder[i]] = i;
        }
        return buildSubtree(preorder, 0, preorder.size() - 1, 
                            inorder, 0, inorder.size() - 1);
    }
};
