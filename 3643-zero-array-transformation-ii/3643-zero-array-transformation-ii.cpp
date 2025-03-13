class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canTransform(nums, queries, mid)) {
                result = mid;
                right = mid - 1;  // Try for a smaller k
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

private:
    bool canTransform(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        // Apply first k queries using difference array
        for (int i = 0; i < k; ++i) {
            int l = queries[i][0], r = queries[i][1], val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n) diff[r + 1] -= val;
        }

        // Compute the prefix sum to get the actual decrements
        int currentDecrement = 0;
        for (int i = 0; i < n; ++i) {
            currentDecrement += diff[i]; // Apply decrements
            if (nums[i] > currentDecrement) return false; // Not enough decrement
        }

        return true;
    }
};
