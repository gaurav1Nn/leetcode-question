class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        vector<int> ans;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(st.empty() || arr[i] > 0) {
                st.push(arr[i]);
            } else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(arr[i])) {
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(arr[i])) {
                    st.pop();
                } else if(st.empty() || st.top() < 0) {
                    st.push(arr[i]);
                }
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};