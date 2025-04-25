class Solution {
public:
    bool check(map<int,int>&m,int a , int n){
        return m.size()==a;
    }
    int count = 0;
    int countCompleteSubarrays(vector<int>& nums) {
        map<int,int> x;
        for(auto i : nums){
            x[i]++;
        }
        int a = x.size();
        int n = nums.size();
        for(int i=0;i<n;i++){
            map<int,int> m;
            for(int j=i;j<n;j++){
                m[nums[j]]++;
                if(check(m,a,n)) count++;
            }
        }
        return count;
    }
};