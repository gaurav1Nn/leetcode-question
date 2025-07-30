class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(),nums.end());
        int long_a = 0 ;
        int ans = 0;
        for(int num : nums){
            if(num==max_ele){
                long_a++;
                ans = max(long_a,ans);
            }
            else long_a =0;

        }
        return ans;
    }
};