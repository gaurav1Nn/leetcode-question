class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n,-1) ;
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(st.size()!=0 && st.top()<=arr[i%n]){
                st.pop();
            }
            if(!st.empty() && i<n){
                nge[i] = st.top();
            }
            st.push(arr[i%n]);
        }
        return nge;
    }
};