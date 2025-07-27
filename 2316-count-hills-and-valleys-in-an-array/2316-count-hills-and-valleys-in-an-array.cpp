class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        // Remove consecutive duplicates
        vector<int> filtered;
        filtered.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                filtered.push_back(nums[i]);
            }
        }

        // Check for hills and valleys
        for (int i = 1; i < filtered.size() - 1; i++) {
            if (filtered[i] > filtered[i - 1] && filtered[i] > filtered[i + 1]) {
                count++; // Hill
            } else if (filtered[i] < filtered[i - 1] && filtered[i] < filtered[i + 1]) {
                count++; // Valley
            }
        }

        return count;
    }
};
