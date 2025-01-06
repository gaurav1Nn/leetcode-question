class Solution {
public:
    string removeDuplicates(string s, int k) {
        if(s.empty()) return "";
        stack<pair<char,int>> st;
        for(char c:s){
            if(!st.empty() && st.top().first==c){
                // Increment count if the same character
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
            }
            else{
                st.push({c,1});
            }
        }
        string ans;
        while(st.size()>0){
             // Correctly append the character count times DONT USE += METHOD
           ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};