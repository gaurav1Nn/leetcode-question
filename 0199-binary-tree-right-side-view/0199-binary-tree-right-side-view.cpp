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
int levels(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(levels(root->left),levels(root->right));
}

void nleveltree(TreeNode* root , int curr , int level,vector<int>& ans){
    if(root==NULL) return ;
    if(curr == level){
        ans[curr] = root->val;
        return ;
    }
    nleveltree(root->left,curr+1 , level,ans); // left recursion
     nleveltree(root->right ,curr+1 , level,ans); // right recursion
}
void levelorder(TreeNode* root,vector<int>& ans){
    int n= ans.size();
    for(int i=0;i<n;i++){
        nleveltree(root,0,i,ans);
        
    }
}
    vector<int> rightSideView(TreeNode* root) {
        int n = levels(root);
        vector<int> ans(n,0);
        levelorder(root,ans);
        return ans;
    }
};