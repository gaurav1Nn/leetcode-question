class Solution {
public:
    // Recursive LCS with memoization
    int solve(int m, int n, vector<vector<int>>& dp, string& str1, string& str2) {
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];

        if(str1[m-1] == str2[n-1]) {
            return dp[m][n] = 1 + solve(m-1, n-1, dp, str1, str2);
        } else {
            return dp[m][n] = max(solve(m-1, n, dp, str1, str2), solve(m, n-1, dp, str1, str2));
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        // Initialize dp table with -1 for memoization
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        solve(m, n, dp, str1, str2);  // Fill dp table

        // Reconstruct the SCS from the dp table
        int i = m, j = n;
        string result = "";

        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                result += str1[i-1];
                i--; j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                result += str1[i-1];
                i--;
            } else {
                result += str2[j-1];
                j--;
            }
        }

        while(i > 0) {
            result += str1[i-1];
            i--;
        }

        while(j > 0) {
            result += str2[j-1];
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
