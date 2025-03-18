
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, bitwise_or = 0, maxLength = 0;
        for (int right = 0; right < nums.size(); right++) {
            while ((bitwise_or & nums[right]) != 0) {
                bitwise_or ^= nums[left]; // Remove leftmost element
                left++;
            }
            
            bitwise_or |= nums[right]; // Add new element
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};