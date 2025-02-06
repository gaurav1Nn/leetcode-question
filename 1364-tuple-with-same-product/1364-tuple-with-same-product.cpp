class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        map<int,int> ans;
        for(int i=0;i<n-1;i++){
            for(int j= i+1;j<n;j++){
                int pr = nums[i]*nums[j];
                count+= 8*ans[pr];
                ans[pr]++;
            }
        }
        return count;
    }
};