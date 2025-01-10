class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        int n= arr.size();
        vector<int> pre(n,0);
        unordered_map<int,int> m;
        pre[0] = arr[0];        
        for(int i=1;i<n;i++){
            pre[i] = arr[i] + pre[i-1];
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(pre[i]==k) {
                count++;
            }
            
            int rem = pre[i] -k;
            if(m.find(rem)!=m.end()) count+=m[rem];
            m[pre[i]]++;
        }
        return count;
    }
};