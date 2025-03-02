class Solution {
public:
vector<vector<int>>ans;
    void solve(vector<int>& nums,vector<int>&per,int c){
        if(c==nums.size()){
            ans.push_back(per);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(per[i]==11){
                per[i]=nums[c];
                solve(nums,per,c+1);
                per[i]=11;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>per(n,11);
       solve(nums,per,0);
       return ans;
    }
};