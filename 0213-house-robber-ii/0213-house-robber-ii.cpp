class Solution {
public:
    int helper(vector<int> nums , int s , int n){
        int prev = 0;
        int prev2 = 0;
        int curr = 0;
        for(int i=s;i<=n;i++){
            curr = max(prev,nums[i]+prev2);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(helper(nums, 0 , n-2) , helper(nums, 1 ,n-1 ));

    }
};