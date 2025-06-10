class Solution {
public:
    void helper(TreeNode* root, vector<string>& ans, string path) {
        if (!root) return;

        // Append current node's value
        if (!path.empty()) path += "->";
        path += to_string(root->val);

        // If it's a leaf node, add the path to ans
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        // Recurse left and right
        helper(root->left, ans, path);
        helper(root->right, ans, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, ans, "");
        return ans;
    }
};
