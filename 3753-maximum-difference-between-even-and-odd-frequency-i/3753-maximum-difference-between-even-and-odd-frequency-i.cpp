class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        map<char,int> ans;
        for(int i=0;i<n;i++){
            ans[s[i]]++;
        }
        int m = 0;
        int mi = INT_MAX;
        for(auto c:ans){
            if(c.second%2==0){
                mi = min(c.second,mi);
            }
            else{
                m = max(m,c.second);
            }
        }
        return m - mi;
    }
};