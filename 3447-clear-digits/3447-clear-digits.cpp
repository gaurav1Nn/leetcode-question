class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
       string ans;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                ans.push_back(s[i]);
            }
            else {
                if(ans.size()>0){
                    ans.pop_back();
                }
            }
        }
        return ans;
    
    }
};