class Solution {
public:
    bool check(vector<int>& r, long long m, int c) {
        long long sum = 0;
        for(int x : r) {
            sum += sqrt(m/x);
            if(sum >= c) return true;
        }
        return false;
    }
    
    long long repairCars(vector<int>& r, int c) {
        long long l = 1, h = 1e14;
        
        while(l < h) {
            long long m = l + (h-l)/2;
            if(check(r, m, c)) h = m;
            else l = m + 1;
        }
        return l;
    }
};