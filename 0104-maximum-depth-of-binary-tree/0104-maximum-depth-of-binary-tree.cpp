
class Solution {
public:
int helper(TreeNode* root){
    if(root==NULL) return 0;
    
    return 1+max(helper(root->left),helper(root->right));
}
    int maxDepth(TreeNode* root) {
       
        int count = helper(root);
        return count;
    }
};