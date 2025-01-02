class Solution {
public:
    long long int helper(TreeNode* root, long long targetsum) { 
        if (root == NULL) return 0;

        // Check if the current node completes the target sum
        long long int count = (root->val == targetsum) ? 1 : 0;

        // Recur for left and right subtrees with updated target sum
        count += helper(root->left, targetsum - root->val);
        count += helper(root->right, targetsum - root->val);

        return count; // if i return value in the llops then the code below it will never run
    }

    int pathSum(TreeNode* root, int targetsum) {
        if (root == NULL) return 0;

        // Count paths starting from the current node
        long long int count = helper(root, (long long)targetsum);

        // Add paths from the left and right subtrees
        count += pathSum(root->left, targetsum);
        count += pathSum(root->right, targetsum);

        return count;
    }
};
