class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans  = 1;
        int min_a = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i] - min_a > k) {
                min_a = nums[i];
                ans++;
            }
        }
        return ans;
    }
};