class Solution {
public:
    int findMin(vector<int>& nums) {
        int mine = INT_MAX;
        int mini=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mine){
                mine = nums[i];
                mini=i;
            }
        }
        return mine;
    }
};