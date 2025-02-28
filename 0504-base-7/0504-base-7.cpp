class Solution {
public:
       string convertToBase7(int n) {
      int x = abs(n); string res;
      do res = to_string(x%7)+res; while(x/=7);
      return (n>=0? "" : "-") + res;
    }
};