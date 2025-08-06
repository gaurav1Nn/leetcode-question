class Solution {
public:
  
int solve(int idx, vector<int>& nums, vector<int>& dp) {
    if (idx == 0) return nums[0];
    if (idx < 0) return 0;
    if (dp[idx] != -1) return dp[idx];

    int rob = nums[idx] + solve(idx - 2, nums, dp); // Take this house
    int skip = solve(idx - 1, nums, dp);            // Skip this house

    return dp[idx] = max(rob, skip);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return solve(n - 1, nums, dp);
}

};