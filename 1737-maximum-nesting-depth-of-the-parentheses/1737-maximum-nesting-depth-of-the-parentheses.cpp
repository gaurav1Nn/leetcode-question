class Solution {
public:
    int maxDepth(string s) {
        if(s.size()<=1) return 0;
        stack<char> st;
        int maxp = 0;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
                count++;
                maxp = max(count,maxp);
            } 
            else if(s[i]==')') {
                count--;
                st.pop();
            }
        }
        
        return maxp;
    }
};