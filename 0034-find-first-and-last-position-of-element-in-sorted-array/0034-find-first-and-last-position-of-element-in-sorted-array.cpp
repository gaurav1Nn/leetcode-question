class Solution {
public:
    // Lower Bound: first index where nums[i] >= target, else -1
    int lowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Upper Bound: first index where nums[i] > target, else -1
    int upperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);

        // If lower bound not found or value doesn't match target
        if (first == -1 || nums[first] != target) {
            return {-1, -1};
        }

        int ub = upperBound(nums, target);
        int last;
        if (ub == -1) last = nums.size() - 1; // target is at end
        else last = ub - 1;

        return {first, last};
    }
};
