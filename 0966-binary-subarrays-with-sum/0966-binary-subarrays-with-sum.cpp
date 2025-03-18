class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int totalCount = 0;
    int currentSum = 0;
    unordered_map<int, int> freq = {{0, 1}}; // Initialize with {0: 1} to handle cases where prefix sum equals goal
    
    for (int num : nums) {
        currentSum += num;
        // If there's a prefix sum that can be subtracted to get the goal
        if (freq.find(currentSum - goal) != freq.end()) {
            totalCount += freq[currentSum - goal];
        }
        freq[currentSum]++;
    }
    return totalCount;
    }
};