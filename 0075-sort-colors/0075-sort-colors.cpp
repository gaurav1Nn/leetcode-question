class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) ans.push_back(0);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) ans.push_back(1);
        }
       for(int i=0;i<nums.size();i++){
            if(nums[i]==2) ans.push_back(2);
        }
        nums = ans ;
    }
};