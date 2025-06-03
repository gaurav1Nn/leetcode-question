class Solution {
public:
    int solve(string& x , string& y , int m , int n , vector<vector<int>>& dp ){
        if(m==0 || n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(x[m-1]==y[n-1]) return dp[m][n] = 1+ solve(x,y,m-1,n-1,dp);
        else {
           return  dp[m][n] = max(solve(x,y,m-1,n,dp) , solve(x,y,m,n-1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int count = 0;
        int m = s.size();
        int n = s.size();
        string y = s;
        reverse(y.begin(),y.end());
        vector<vector<int>> dp(m+1, vector<int>(n+1 , -1));
        return solve(s,y,m,n,dp);
    }
};