class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int maxVal = nums[i];
            int minVal = nums[i];
            for (int j = i + 1; j < n; j++) {
                maxVal = max(maxVal, nums[j]);
                minVal = min(minVal, nums[j]);
                count += (maxVal - minVal);
            }
        }
        return count;
    }
};
