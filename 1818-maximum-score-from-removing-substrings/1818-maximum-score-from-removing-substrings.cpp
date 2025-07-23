class Solution {
public:
    int remove(string &s , string pattern , int score){
        stack<char> st;
        int total = 0;
        for(char c:s){
            if(!st.empty() && st.top() == pattern[0] && c == pattern[1]){
                st.pop();
                total+=score;

            }
            else{
                st.push(c);
            }
        }
        s= "";
        while(!st.empty()){
            s+= st.top();
            st.pop();
        }
        reverse(s.begin() , s.end());
        return total;
    }
    int maximumGain(string s, int x, int y) {
        int ans= 0;
        if(x>y) {
            ans+=remove(s,"ab" , x);
            ans+= remove(s,"ba",y);

        } else{
            ans += remove(s , "ba" , y);
            ans+= remove(s,"ab",x);
        }
        return ans;
    }
};