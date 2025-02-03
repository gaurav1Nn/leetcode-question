class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int count1 = 1;
        int Mcount1=0;
        int count2=1;
        int Mcount2  = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                count1++;
               
            }
            else {
                count1=1;
            }
            Mcount1 = max(count1,Mcount1);
        }
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                count2++;
               
            }
            else {
                count2=1;
            }
             Mcount2 = max(count2,Mcount2);
        }
        if(Mcount1==0) Mcount1=1;
        if(Mcount2==0) Mcount2=1;
        // return count1++;
        return max(Mcount1,Mcount2);
    }
};