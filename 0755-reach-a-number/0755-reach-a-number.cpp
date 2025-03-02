class Solution {
public:
     int reachNumber(int t) {
        int n = ceil((sqrt(1+8.*abs(t))-1)/2), d = n*(n+1)/2-t;
        return n + (d%2)*(n%2+1);
    }
};