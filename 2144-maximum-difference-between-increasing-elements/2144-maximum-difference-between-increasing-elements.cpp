class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = 0;
        int maxd = 0;
        for(int i = 0; i< nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                diff = nums[j] - nums[i];
                maxd = max(diff , maxd);
            }
        }
        if(maxd == 0) return -1;
        return maxd;
    }
};