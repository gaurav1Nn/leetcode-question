class Solution {
public:
    void solve(int i , vector<vector<int>>& ans , vector<int>& c , int target , vector<int>& curr ){
        if(i==c.size()){
            if(target==0){
                ans.push_back(curr);
                return ;
            }
            else return ;
        }
        if(c[i]<=target){
            curr.push_back(c[i]);
            solve(i,ans,c,target-c[i] , curr);
            curr.pop_back();
        }
        solve(i+1,ans,c,target , curr);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> ans ;
        vector<int> curr ;

        solve( 0 , ans ,c , target , curr );
        return ans;
    }
};