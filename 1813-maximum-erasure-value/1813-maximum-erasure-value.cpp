

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp; // stores element and its last index
        int maxSum = 0, currSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            int num = nums[right];

            // If duplicate found in window
            if (mp.count(num) && mp[num] >= left) {
                // Remove elements from left to mp[num]
                while (left <= mp[num]) {
                    currSum -= nums[left];
                    left++;
                }
            }

            currSum += num;
            mp[num] = right;
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
