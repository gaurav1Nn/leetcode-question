class Solution {
public:
    vector<int> Nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> Pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = Nse(arr);
        vector<int> pse = Pse(arr);
        long long total = 0;
        int n = arr.size();
        int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (long long) arr[i] * left * right) % mod;
        }
        return (int) total;
    }
};