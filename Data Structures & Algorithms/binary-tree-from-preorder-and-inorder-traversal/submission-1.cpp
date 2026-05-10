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
    TreeNode* buildSubtree(const vector<int>& preorder, int pl, int pr, 
                           const vector<int>& inorder, int il, int ir) {
        if (pl > pr || il > ir) return nullptr;

        TreeNode* root = new TreeNode(preorder[pl]);

        int mid = find(inorder.begin() + il, inorder.begin() + ir + 1, preorder[pl]) - inorder.begin();

        int size_left = mid - il;

        root->left = buildSubtree(preorder, pl + 1, pl + size_left,
                                  inorder, il, mid - 1);
        root->right = buildSubtree(preorder, pl + size_left + 1, pr,
                                   inorder, mid + 1, ir);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildSubtree(preorder, 0, preorder.size() - 1, 
                            inorder, 0, inorder.size() - 1);
    }
};
