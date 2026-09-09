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
        unordered_map<int, int> indexes;
        for (int i = 0; i < inorder.size(); i++) {
            indexes[inorder[i]] = i;
        }

        int i = 0;

        return subtree(preorder, inorder, indexes, i, 0, inorder.size()-1);
    }

    TreeNode* subtree(vector<int> &preorder, 
                      vector<int> &inorder, 
                      unordered_map<int, int> &indexes, 
                      int &i, int l, int r) {
        if (i >= preorder.size() || l > r) 
            return nullptr;

        // next element in preoder is root
        TreeNode* node = new TreeNode(preorder[i]);

        // find that element in inorder
        int j = indexes[preorder[i]];

        i++;

        // l --> j-1  belong to left subtree
        node->left = subtree(preorder, inorder, indexes, i, l, j-1);

        // j+1 --> r  belong to right subtree
        node->right = subtree(preorder, inorder, indexes, i, j+1, r);

        return node;
    }
};
