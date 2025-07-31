class Solution {
public:
    void  solve(vector<int>& nums,vector<vector<int>>& arr , int i , vector<int>& curr){
        if(i==nums.size()) {
            arr.push_back(curr);
            return ;
        } 
        curr.push_back(nums[i]);
        solve(nums , arr , i+1 , curr);
        curr.pop_back();
        solve(nums , arr , i+1 , curr);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> arr ;

        vector<int> curr;
        solve(nums ,arr  , 0 , curr);;
        return arr;
    }
};