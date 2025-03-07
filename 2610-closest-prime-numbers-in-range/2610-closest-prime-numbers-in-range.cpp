class Solution {
public:
    bool isprime(int n){
        if(n<=1)  return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans;
        vector<int> arr;
        for(int i=left;i<=right;i++){
            if(isprime(i)) {
                arr.push_back(i);
            }
        }
        if(arr.size()<=1){
             ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        long long  min = INT_MAX;
        long long sub  = 0;
        int first = 0;
        int second = 0;
        for(int i=0;i<arr.size()-1;i++){
            sub = arr[i+1]-arr[i];
            if(sub<min) {
                min = sub;
                first = arr[i];
                second = arr[i+1];
            }
        }
        ans.push_back(first);
        ans.push_back(second);

        if(ans.size()<=1) {
            ans[0] = -1;
            ans.push_back(-1);
            return ans;
        }
        else return ans;

    }
};