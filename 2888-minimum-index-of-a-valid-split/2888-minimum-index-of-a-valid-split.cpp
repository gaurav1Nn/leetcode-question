class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> ans;
        int n = nums.size();
        int a = n/2;
        for(int a : nums){
            ans[a]++;
        }
        int element = 0;
        for(auto b : ans){
            if(b.second>a){
                element = b.first;
            }
        }
        int total = ans[element];
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==element) count++;
            int lsize = i+1;
            int rsize = n -(i+1);
            if(count>(lsize/2) && (total-count)>rsize/2) return i;
        }
    return -1;
    }
};