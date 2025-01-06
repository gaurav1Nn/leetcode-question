class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        if (s.empty()) return ""; 
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if( st.size()>0 && s[i]==st.top()){
                st.pop();
            }
            else st.push(s[i]);
        }
        string ans;
        while(st.size()>0){
            char x = st.top();
            ans+=x;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};