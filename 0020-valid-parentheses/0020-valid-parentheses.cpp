class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s[0]==')'|| s[0]== '}' || s[0]==']') return false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]== '{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if(st.empty()) return false;
            int x = st.top();
            if((x=='(' and s[i]==')') or (x=='{' and s[i]=='}') or (x=='[' and s[i]==']')) {
                st.pop(); 
            }
            
            else return false; //return false if something is wrong.

        }
        return st.empty();
    }
};