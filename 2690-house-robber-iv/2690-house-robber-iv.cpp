class Solution {
public:
    bool check(vector<int>& n, int m, int k) {
        int c = 0;  // count
        int p = -2; // prev
        
        for(int i = 0; i < n.size(); i++) {
            if(n[i] <= m && i > p + 1) {
                c++;
                p = i;
            }
        }
        return c >= k;
    }
    
    int minCapability(vector<int>& n, int k) {
        int l = 1;
        int r = 1e9;
        
        while(l < r) {
            int m = l + (r - l)/2;
            if(check(n, m, k)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};