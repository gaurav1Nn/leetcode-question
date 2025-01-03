
class Solution {

public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->right),levels(root->left));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int x = levels(root->left);
        int y = levels(root->right);
        if(abs(x-y)>1) return false;
        bool left = isBalanced(root->left); // for checking each node
        bool right= isBalanced(root->right);
        if(!right || !left)  return false;
        else return true;
    }
};