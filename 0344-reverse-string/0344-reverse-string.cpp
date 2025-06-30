class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        vector<char> a ;
        for(int i=n-1 ; i>=0 ; i--){
            a.push_back(s[i]);
        }
        s = a;

    }
};