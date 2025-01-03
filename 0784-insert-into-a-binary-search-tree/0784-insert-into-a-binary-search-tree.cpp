class Solution {
public:
    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        
        if (val < root->val) {
            if (root->left == NULL) {
                root->left = new TreeNode(val);
            } else {
                insert(root->left, val);
            }
        } else {  // Assuming val is always unique
            if (root->right == NULL) {
                root->right = new TreeNode(val);
            } else {
                insert(root->right, val);
            }
        }
        
        return root;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, val);
    }
};