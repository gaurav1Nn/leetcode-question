class Solution {
public:
    int reverse(int a){
        int ans=0;
        while(a!=0){
            int x = a%10;
            ans = ans*10 + x;
            a=a/10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for(int x: nums){
            arr.push_back(reverse(x));
        }
        nums.insert(nums.end(),arr.begin(),arr.end());
        unordered_set<int> a;
        for(int x: nums){
            a.insert(x);
        }
        return a.size()-1;
    }
};