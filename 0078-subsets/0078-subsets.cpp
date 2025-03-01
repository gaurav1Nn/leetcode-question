class Solution {
public:
    void helper(vector<int>& nums , int idx , vector<vector<int>>& ans, vector<int>v){
        if(idx == nums.size()){
            ans.push_back(v);
            return ;
        }
        helper(nums,idx+1,ans, v);
        v.push_back(nums[idx]);
        helper(nums,idx+1,ans, v);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(nums , 0, ans , v);
        return ans;
    }
};