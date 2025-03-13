class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pi = upper_bound(nums.begin(),nums.end(),0) - nums.begin();
        pi = n - pi;
        int ni = lower_bound(nums.begin(),nums.end(),0) -  nums.begin();
        return max(ni , pi);
    }
};