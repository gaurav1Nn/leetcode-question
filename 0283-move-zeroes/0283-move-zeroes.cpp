class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int  n  = nums.size();
        if(n<=1) return ;
        vector<int> a;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) a.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) a.push_back(nums[i]);
        }
        nums = a;
    }
};