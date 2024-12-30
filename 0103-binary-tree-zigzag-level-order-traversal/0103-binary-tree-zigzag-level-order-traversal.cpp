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
void nleveltree(TreeNode* root, int count ,int target, vector<int>& v ){
    if(root==NULL) return ;
    if(count==target) v.push_back(root->val);
    nleveltree(root->left,count+1,target,v);
    nleveltree(root->right,count+1,target,v);

}
void revnleveltree(TreeNode* root, int count ,int target, vector<int>& v ){
    if(root==NULL) return ;
    if(count==target) v.push_back(root->val);
    revnleveltree(root->right,count+1,target,v);
    revnleveltree(root->left,count+1,target,v);

}
    void lorder(TreeNode* root , vector<vector<int>>& ans){
        int n = levels(root);
        for(int i= 1;i<=n;i++){
            vector<int> v;
            if(i%2==0) revnleveltree(root, 1 , i, v);
            else nleveltree(root, 1 , i, v);
            ans.push_back(v);
            cout<<endl;
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        lorder(root,ans);
        return  ans;
    }
};