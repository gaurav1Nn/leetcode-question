 class Solution {
public:
 int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // dp[i][j] = min falling path sum ending at (i, j)
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Base case: first row is same as matrix
        for (int j = 0; j < cols; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill dp table row by row
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int straight = dp[i - 1][j];
                int leftDiag = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                int rightDiag = (j < cols - 1) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min(straight, min(leftDiag, rightDiag));
            }
        }
        // Find minimum in last row
        int ans = 1e9;
        for (int j = 0; j < cols; j++) {
            ans = min(ans, dp[rows - 1][j]);
        }
        return ans;
    }
};
