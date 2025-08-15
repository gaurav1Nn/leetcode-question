class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        if(n==1) return true;
        while(n%4==0){
            n = n/4;
            
        }
        return n== 1;
        return false;
    }
};