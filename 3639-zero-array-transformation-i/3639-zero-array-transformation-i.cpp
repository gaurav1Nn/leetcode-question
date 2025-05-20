class Solution {
public:
    bool isA0(const vector<int>& nums){
        for(int num : nums){
            if(num > 0) return false;
        }
        return true;
    }

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        vector<int> diff(n + 1, 0); // difference array for range updates

        // Apply all range updates in O(q) time
        for(const auto& query : q){
            int l = query[0];
            int r = query[1];
            diff[l] -= 1;
            if(r + 1 < n) diff[r + 1] += 1;
        }

        // Apply the difference array to nums
        int curr = 0;
        for(int i = 0; i < n; ++i){
            curr += diff[i];
            nums[i] += curr;
        }

        return isA0(nums);
    }
};
