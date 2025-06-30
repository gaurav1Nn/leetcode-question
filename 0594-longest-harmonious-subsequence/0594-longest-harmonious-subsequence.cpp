class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, best = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {
            while (nums[j] - nums[i] > 1) ++i;
            if (nums[j] - nums[i] == 1) {
                best = max(best, j - i + 1);
            }
        }
        return best;
    }
};