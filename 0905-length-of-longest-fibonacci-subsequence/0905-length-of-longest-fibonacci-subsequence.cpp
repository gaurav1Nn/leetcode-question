class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxl = 0;
        unordered_set<int> ans(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int x = arr[i];
                int y = arr[j];
                int len = 2;  // Reset len for each new pair
                
                while(ans.count(x + y)) {
                    int sum = x + y;
                    x = y;
                    y = sum;
                    len++;
                }
                maxl = max(len, maxl);
            }
        }
        
        return maxl >= 3 ? maxl : 0;  // Simplified return statement
    }
};