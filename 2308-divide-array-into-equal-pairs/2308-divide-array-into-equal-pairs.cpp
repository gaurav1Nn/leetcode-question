class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> ans;
        for(int i : nums){
            ans[i]++;
        }
        for(auto i : ans){
            if(i.second %2!=0) return false;
        }
        return true;
    }

};