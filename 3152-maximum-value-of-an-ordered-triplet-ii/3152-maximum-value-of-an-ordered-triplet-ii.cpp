// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long long maxele = 0;
//         long long minele = INT_MAX;
//         long long maxp = 0;
//         int n = nums.size();
//         int a = 0;
//         for(int i=0;i<n-2;i++){
//             maxele = max(maxele,nums[i]);
//             a = i;
//         }
//         int b = 0;
//         for(int i=a ; i<n-1;i++){
//             minele = min(nums[i],minele);
//             b = i;
//         }
//         for(int c = b;c<n;c++){
//             maxp = max(maxp,nums[c]);
//         }
//         if(a == n-1) return 0;
//         long long x = (maxele - minele) * maxp;
//         return x;
//     }
// };
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
        }
        long long res = 0;
        for (int j = 1; j < n - 1; j++) {
            res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return res;
    }
};