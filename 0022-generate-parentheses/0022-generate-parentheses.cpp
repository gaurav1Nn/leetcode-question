class Solution {
public:
    void solve(vector<string>& ans, string s, int open, int close, int n) {
        if (s.size() == 2 * n) { // If length reached
            ans.push_back(s);
            return;
        }
        
        if (open < n)  // Pick '(' if available
            solve(ans, s + "(", open + 1, close, n);
        
        if (close < open) // Pick ')' only if valid
            solve(ans, s + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", 0, 0, n);
        return ans;
    }
};
