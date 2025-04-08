class Solution {
public:
    bool check(vector<int> nums){
        map<int,int> ans;
        int n = nums.size();
        if(n<=1) return true;
        for(int a : nums){
            ans[a]++;
        }
        for(auto x : ans){
            if(x.second > 1){
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) {
            if(!check(nums)){
                return 1;
            }
        }
        int count = 0;
        if(check(nums)) return count;
        int i = 3;
        while(!check(nums)){
            if(nums.size()>=3) {
                vector<int> a(nums.begin()+i,nums.end());
                check(a);
                count++;
                // i+=3;
                nums = a;
            }
            else {
                break;
            }
          
        }
        if(check(nums)) return count;
        return count+1;
    }
};