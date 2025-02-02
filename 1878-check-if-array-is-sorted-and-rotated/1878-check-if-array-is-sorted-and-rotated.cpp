class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();
        int check = 0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                check++;
            }
        }
        if(nums[n-1]>nums[0]) check++;
        return check<=1;
    }
};