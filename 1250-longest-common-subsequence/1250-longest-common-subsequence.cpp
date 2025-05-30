class Solution {
public:
    int longestCommonSubsequence(string x, string y) {
        int n= x.size();
        int m = y.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1,0));

        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<m+1;j++){
        //         if(i==0 || j==0){
        //             dp[i][j] = 0;
        //         }
        //     }
        // }
       for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1] ==  y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};