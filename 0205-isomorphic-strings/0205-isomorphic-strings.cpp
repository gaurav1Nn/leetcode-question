class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        int maps[256]={0};
        int mapt[256] ={0};
        // they both will store the ascci value 
        for(int i=0;i<s.length();i++){
            if((maps[s[i]]!=0) && (maps[s[i]]!=t[i])){
                return false;
            }
            if(mapt[t[i]]!=0 && mapt[t[i]]!=s[i] ){
                return false;
            }
            maps[s[i]]= t[i];
            mapt[t[i]] = s[i];
            
        }

        return true;
    }
};
