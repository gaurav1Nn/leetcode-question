class Solution {
public:
    int8_t dp[201][10001] = {[0 ... 200] = {[0 ... 10000] = -1}};  // all initialized to -1 (use dynamic vector to generalize to higher array size & possible sums)
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if(totalSum & 1) return false;
        return subsetSum(nums, totalSum / 2);
    }
    bool subsetSum(vector<int>& nums, int sum, int i = 0) {
        if(sum == 0) return true;
        if(i >= size(nums) || sum < 0) return false; 
        if(dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = subsetSum(nums, sum - nums[i], i + 1) || subsetSum(nums, sum, i + 1);
    }
};