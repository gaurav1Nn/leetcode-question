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
    int maxd = 0;
    int dia = 0;
    int levels(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        dia = levels(root->left) + levels(root->right);
        maxd = max(dia,maxd);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxd;
    }
};