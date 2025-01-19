
class Solution {
public:
    void helper(TreeNode* root , int lo , int hi){
        if(root==NULL) return ;
        while(root->left!=NULL){
            if(root->left->val<lo){
                root->left=root->left->right;
            }
            else if(root->left->val>hi){
                root->left=root->left->left;
            }
            else break;
        }
        while(root->right!=NULL){
            if(root->right->val>hi){
                root->right=root->right->left;
            }
            else if(root->right->val<lo){
                root->right=root->right->right;
            }
            else break;
        }
        helper(root->left,lo,hi);
        helper(root->right,lo,hi);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        helper(dummy,low,high);
        return dummy->left;
    }
};