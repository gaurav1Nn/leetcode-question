class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> ans;
        for(int x : nums){
            ans[x]++;
        }
        vector<int> a;
        int n = nums.size();
        for(auto x : ans){
            if(x.second > n/3) {
                a.push_back(x.first);
            }
        }
        return a;
    }
};