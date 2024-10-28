class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter  = 0 ;
        string ans;
        for(int i=0;i<s.length();i++){
            if(counter>0 && s[i]=='('){
                ans+=s[i];
                counter++;
            } 
            if(s[i]==')' ) counter--;
            if(counter>0 && s[i]==')'){
                ans+=s[i];
                counter--;
            } 
            if(s[i]=='(' ) counter++;
            

        }
        return ans;
        
    }
};