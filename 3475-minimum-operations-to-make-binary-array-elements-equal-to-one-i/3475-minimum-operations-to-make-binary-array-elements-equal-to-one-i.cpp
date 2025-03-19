class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i=2;i<nums.size();i++){
            if(nums[i-2]==0){
                count++;
                nums[i-2]^=1;
                nums[i-1]^=1;
                nums[i]^=1;
            }
        }
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum==nums.size()) return count;
        else return -1;
    }
};