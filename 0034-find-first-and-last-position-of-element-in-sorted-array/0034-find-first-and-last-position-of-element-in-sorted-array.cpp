class Solution {
public:
    // Lower Bound: first index where nums[i] >= target
    int lowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    // Upper Bound: first index where nums[i] > target
    int upperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) - 1;

        // Check if target exists in the array
        if (first >= nums.size() || nums[first] != target) {
            return {-1, -1};
        }
        return {first, last};
    }
};
