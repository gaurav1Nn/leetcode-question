class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;
        unordered_map<char,int> m;
        int odd_count = 0;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(auto x : m){
            if(x.second%2!=0) odd_count++;
        }
        return odd_count<=k;
    }
};