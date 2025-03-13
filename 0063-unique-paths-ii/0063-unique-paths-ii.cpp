class Solution {
public:
    // int mod = (int)(1e9 + 7); // Fixed typo in comment
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        // Edge cases: if start or end has obstacle
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) 
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Initialize first cell
        dp[0][0] = 1;
        
        // Initialize first row
        for (int j = 1; j < m; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            }
        }
        
        // Initialize first column
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            }
        }
        
        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};