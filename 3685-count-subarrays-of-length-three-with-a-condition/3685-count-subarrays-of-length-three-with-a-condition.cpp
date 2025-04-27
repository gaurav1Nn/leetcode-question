class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i <= n - 3; ++i) {
            if (2 * (nums[i] + nums[i + 2]) == nums[i + 1]) {
                count++;  
            }
        }
        return count;
    }
};
