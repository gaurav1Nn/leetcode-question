
class Solution {
public:
    void helper(TreeNode* root , vector<int> s, vector<vector<int>>& ans,int targetsum){
        if(root==NULL) return ;
       
        s.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            // s.push_back(root->val);
            if(root->val==targetsum) ans.push_back(s);
        }
        targetsum = targetsum - root->val;
        helper(root->left,s,ans,targetsum);
        helper(root->right,s,ans,targetsum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        vector<vector<int>> ans;
        helper(root,v,ans,targetSum);
        return ans;
    }
};