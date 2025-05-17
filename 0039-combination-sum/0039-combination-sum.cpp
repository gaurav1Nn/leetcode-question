class Solution {
public:
    void solve (int index ,vector<int>& c , int target , vector<int>&v , vector<vector<int>>& result ){
        if(index == c.size()) {
            if (target == 0) {
                result.push_back(v); // Found a valid combination
            }
            return;
        }
        if(c[index]<=target){
            v.push_back(c[index]);
            solve(index,c,target - c[index],v ,result );
            v.pop_back(); //
        }
        solve(index+1,c,target,v ,result );

    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> result;
        vector<int> v;
        solve(0,c,target,v,result);
        
        return result;
    }
};