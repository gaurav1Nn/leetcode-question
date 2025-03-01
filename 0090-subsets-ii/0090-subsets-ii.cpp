class Solution {
public:
    void helper(vector<int>& nums , set<vector<int>>& ans , vector<int> v , int idx){
        if(idx==nums.size()){
            ans.insert(v);
            return ;
        }
        helper(nums, ans,v , idx+1);
        v.push_back(nums[idx]);
        helper(nums, ans,v , idx+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        helper(nums, ans,v , 0);
        vector<vector<int>> finalans(ans.begin(),ans.end());
        return finalans;
    }
};