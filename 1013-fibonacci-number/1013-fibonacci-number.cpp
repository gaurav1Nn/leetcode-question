class Solution {
public:
    int helper(int a){
        if(a==0 ) return 0;
        if(a==1) return 1;
        return helper(a-1) + helper(a-2);
    }
    int fib(int n) {
        int x = helper(n);
        return x;
    }
};