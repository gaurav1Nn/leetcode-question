class Solution {
public:
    int helper(vector<vector<int>>& dp , int n , int i , int amount , vector<int>& coins){
        if(i==n) {
            if(amount == 0) return  0;
            else return   INT_MAX-1;

        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int not_pick = helper(dp,n,i+1,amount , coins);
        if(amount-coins[i]<0) return not_pick;
        int pick = 1 + helper(dp , n , i , amount - coins[i] , coins);
        return dp[i][amount] = min(pick,not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // if(n<=1){
        //     if(coins[0]>amount) return -1;
        //     else if(amount%coins[0]!=0) return -1;
        // }
        vector<vector<int>> dp(n+1 , vector<int>(amount+1,-1));
        int x =  helper(dp , n , 0 , amount , coins);
        if(x==INT_MAX-1) return -1;
        else return x;
    }
};