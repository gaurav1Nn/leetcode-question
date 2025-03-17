class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        if(n%2!=0) return false;
        for(int i=0;i<n;i+=2){
            if(nums[i]!=nums[i+1]) return false;
        }
        return true;
    }
};