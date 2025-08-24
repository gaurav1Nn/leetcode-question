class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, res = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;

            // shrink window if more than 1 zero
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            res = max(res, right - left); 
            // note: right - left (not +1), because we must delete one element
        }
        return res;
    }
};
