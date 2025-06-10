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
    // TreeNode* helper(TreeNode* root , TreeNode* root2){
    //     if(root == NULL) return root2;
    //     root2->val = root->val;
    //     root2->left = root->right;
    //     root2->right = root->left;
    //     helper(root->left,root2->left);
    //     helper(root->right,root2->right);
    //     return root2;
    // }
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left,root->right);
        }
        return root;
        
    }
};