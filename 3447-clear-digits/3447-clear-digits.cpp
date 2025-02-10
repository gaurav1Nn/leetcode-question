class Solution {
public:
    string clearDigits(string s) {
    int n=s.size();
    stack<char>st;
    string res;
      
    for(int i=0;i<n;i++){
        if(isalpha(s[i])){
            st.push(s[i]);
        }
        else {
            if(st.size()>0){
                st.pop();
            }
        }
    }
 
while(!st.empty()){
    char a = st.top();
    st.pop();
    res+=a;

}
reverse(res.begin(),res.end());
return res;
    }
};