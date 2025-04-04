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
    int max_height=0;
    auto dfs(TreeNode* root , int curr){
        if(root==NULL){
            return ;
        }
        max_height=max(max_height,curr);
        dfs(root->left,curr+1);
        dfs(root->right,curr+1);
    }
    TreeNode* lca(TreeNode* root , int curr){
        if(root == NULL || curr==max_height){
            return root;
        }
        TreeNode* left=lca(root->left,curr+1);
        TreeNode* right=lca(root->right,curr+1);
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root,0);
        return lca(root,0);
    }
};