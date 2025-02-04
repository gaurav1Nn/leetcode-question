class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int max_sum =0;
        int maxe=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxe){
                maxe=nums[i];
            }
            if(i==0) sum+=nums[i];
            else if(nums[i-1]<nums[i]){
                sum+=nums[i];
                max_sum=max(max_sum,sum);
            }
            else {
                sum = nums[i];
            }
        }
        if(max_sum==0 || max_sum<maxe) return maxe;
        return max_sum;
    }
};