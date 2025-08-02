class Solution {
public:
  void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int> v, int idx){
    ans.push_back(v) ; // add current subset
    for(int i =idx ; i<nums.size();i++){
        if(i>idx && nums[i]==nums[i-1]) continue;
        v.push_back(nums[i]);
        helper(nums,ans,v,i+1);
        v.pop_back();
    }
  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        helper(nums,ans,v,0);
        return ans;
    }
};