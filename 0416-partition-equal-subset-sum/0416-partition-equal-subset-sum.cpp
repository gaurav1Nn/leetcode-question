class Solution {
public:
    bool solve(vector<vector<int>>& dp , vector<int>& arr , int a , int i){
        if(a==0) return true;
        if(i ==0){
            return arr[0]==a;
        }
        if(dp[i][a]!=-1) return dp[i][a];
        bool not_take = solve(dp,arr,a,i-1);
        bool take = false;
        if(arr[i]<=a) take = solve(dp,arr,a-arr[i],i-1);
        return dp[i][a] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ; 
        for(int x : nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        int a = sum/2;
        vector<vector<int>> dp(n , vector<int>(a+1 , -1));
        return solve(dp,nums,a,n-1);
    }
};