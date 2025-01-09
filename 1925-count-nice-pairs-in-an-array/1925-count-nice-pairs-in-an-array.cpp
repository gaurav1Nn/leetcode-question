class Solution {
public:
    int rev(int n){
        int r =0;
        while(n>0){
            int x = n%10;
            r= r*10 + x;
            n=n/10;
        }
        return r;
    }
   
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        map<int,int> m;
        const int MOD = 1e9 + 7;
        for(int i=0;i<n;i++){
            int x = nums[i] - rev(nums[i]);
            if(m.find(x)!=m.end()){
                count = (count + m[x]) % MOD;//adding frequency
                m[x]++;
                // m.erase(m[x]);
            }
            else{
                m[x]++;
            }
        }
        return count;
    }
};