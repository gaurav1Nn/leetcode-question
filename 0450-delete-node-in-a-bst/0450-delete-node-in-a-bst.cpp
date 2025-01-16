
class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right!=NULL){
            pred = pred->right;

        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        // firt case if the target value is leaf node
        if(root->val==key) {
            if(root->right==NULL && root->left ==NULL){
                return NULL;
            }
            if(root->left==NULL || root->right == NULL){
                if(root->left!=NULL) return root->left;
                else return root->right; 
            }
            if(root->left!=NULL && root->right!=NULL){
                TreeNode* pred = iop(root);
                root->val = pred->val;
                // key is already deleted therefore we have to delete now pred val which is repeated
                root->left = deleteNode(root->left, pred->val);
            }
        }
        if(root->val >key){
            root->left = deleteNode(root->left,key);
        }
        else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};