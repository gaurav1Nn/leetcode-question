class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n & 1;
        n = n>>1;

        while(n>0){
            int curr = n & 1;
            if(curr==prev) return false;
            else prev = curr;
            n = n>>1;
        }
        return true;
    }
};