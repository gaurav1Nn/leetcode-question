
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
    void lorder(TreeNode* root , vector<vector<int>>& ans){
        int n = levels(root);
        for(int i= 1;i<=n;i++){
            vector<int> v;
            nleveltree(root, 1 , i, v);
            ans.push_back(v);
            cout<<endl;
        }
        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        lorder(root,ans);
        return  ans;

    }
};