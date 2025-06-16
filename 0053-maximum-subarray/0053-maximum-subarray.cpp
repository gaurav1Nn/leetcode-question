class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_s = INT_MIN;
        int curr = 0;
        for(int i=0;i<nums.size();i++){
            curr += nums[i];
            max_s = max(curr , max_s);
            if(curr < 0) curr =0;
        }
    return max_s;
    }
};