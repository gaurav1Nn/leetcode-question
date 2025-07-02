class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int e = 0;
        for(int i = 0 ; i<nums.size();i++){
            sum+=nums[i];
        }
        for(int i=1;i<=nums.size();i++){
            e+=i;
        }
        return e-sum;
    }
};