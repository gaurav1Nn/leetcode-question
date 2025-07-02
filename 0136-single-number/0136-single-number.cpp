class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            s[nums[i]]++;
        }
        for(auto x : s){
            if(x.second == 1) return x.first;
        }
        return nums[0];
    }
};