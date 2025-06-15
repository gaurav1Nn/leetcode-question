

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), best = 0;
        stack<int> st;
        st.push(-1);                    // sentinel

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {                    // s[i] == ')'
                st.pop();               // try to match with a '('
                if (st.empty()) {
                    st.push(i);         // new sentinel (no match)
                } else {
                    best = max(best, i - st.top());
                }
            }
        }
        return best;
    }
};