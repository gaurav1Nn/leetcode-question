class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> ans;
        if(n<k) k = k%n;
        for(int i=n-k;i<n ; i++){
            ans.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            ans.push_back(nums[i]);
        }
        nums= ans;
    }
};