class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int pre = 1;
        int suf = 1;
        int maxi = 0;
        for(int i=0;i<n;i++){
            if(pre == 0) pre=1;
            if(suf == 0) suf = 1;
            pre = pre * nums[i];
            suf = suf * nums[n-i-1];
            maxi = max(maxi , max(pre,suf));
        }
        return maxi;
    }
};