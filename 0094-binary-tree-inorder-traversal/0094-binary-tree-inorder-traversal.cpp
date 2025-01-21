
class Solution {
public:
  // MORRIS traversal 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){ // find the prep
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred=pred->right;
                }
                if(pred->right==NULL){ // LINK
                    pred->right = curr;
                    curr= curr->left;
                }
                else{ // pred->right == curr // unlink
                    pred->right =NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else { // curr->left == NULL
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;

    }
};