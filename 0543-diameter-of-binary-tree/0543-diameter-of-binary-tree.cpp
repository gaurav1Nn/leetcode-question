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
   
    int levels(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }
     void visit(TreeNode* root , int &maxd){
        if(root==NULL) return ;
        int dia = levels(root->left) + levels(root->right);
        maxd = max(dia,maxd);
        visit(root->left,maxd);
        visit(root->right,maxd);
        // return maxd;
    } // this approoach is loved by interviewrs
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd = 0;
        visit(root , maxd);
        return maxd;
    }
};