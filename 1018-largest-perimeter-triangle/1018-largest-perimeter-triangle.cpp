class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: sort the array
        int n = nums.size();
        
        // Step 2: sliding window from the end
        for (int i = n - 1; i >= 2; i--) {
            int a = nums[i], b = nums[i - 1], c = nums[i - 2];
            if (b + c > a) {  // valid triangle condition
                return a + b + c; // maximum perimeter found
            }
        }
        return 0; // if no triangle possible
    }
};