class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0 , maxa = 0 ;
        for(int j= 0 ; j<n;j++){
            while(nums[j]-nums[i]>1) i++;
            if(nums[j]-nums[i]==1) {
                maxa = max(maxa,j-i+1);
            }
        }
        return maxa;
    }
};