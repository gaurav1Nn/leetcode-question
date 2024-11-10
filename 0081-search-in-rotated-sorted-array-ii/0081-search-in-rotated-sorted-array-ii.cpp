class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow

            if (nums[mid] == k) return true;

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            } 
            else if (nums[low] <= nums[mid]) { // Left half is sorted
                if (k >= nums[low] && k < nums[mid]) {
                    high = mid - 1; // Search in the left half
                } else {
                    low = mid + 1; // Search in the right half
                }
            } 
            else { // Right half is sorted
                if (k > nums[mid] && k <= nums[high]) {
                    low = mid + 1; // Search in the right half
                } else {
                    high = mid - 1; // Search in the left half
                }
            }
        }
        return false; // k not found
    }
};