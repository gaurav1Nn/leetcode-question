class Solution {
public:
    int solve(string& x , string& y ,int n , int m , vector<vector<int>>& dp){
        if(m==0 || n==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(x[n-1] == y[m-1]) return dp[n][m]=  1 + solve(x,y,n-1,m-1,dp) ;
        else{
            return dp[n][m] = max(solve(x,y,n-1,m,dp),solve(x,y,n,m-1,dp));
        }

    }
    int minInsertions(string s) {
        int n = s.size();
        int m = s.size();
        vector<vector<int>> dp( n+1 ,vector<int> ( n+1 , -1) );
        string y = s;
        reverse(y.begin(),y.end());
        int x = solve(s , y , n, m , dp );
        return s.size() - x;
    }
};