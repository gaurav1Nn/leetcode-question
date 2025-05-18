class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int M = 1e9 + 7;
        vector<vector<int>> p;
        int t = pow(3, m);
        for (int i = 0; i < t; ++i) {
            vector<int> v(m);
            int x = i;
            for (int j = 0; j < m; ++j) {
                v[j] = x % 3;
                x /= 3;
            }
            bool ok = true;
            for (int j = 1; j < m; ++j)
                if (v[j] == v[j - 1]) ok = false;
            if (ok) p.push_back(v);
        }
        int k = p.size();
        vector<vector<int>> g(k);
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j) {
                bool ok = true;
                for (int l = 0; l < m; ++l)
                    if (p[i][l] == p[j][l]) ok = false;
                if (ok) g[i].push_back(j);
            }
        vector<int> dp(k, 1);
        for (int i = 1; i < n; ++i) {
            vector<int> ndp(k);
            for (int j = 0; j < k; ++j)
                for (int l : g[j])
                    ndp[j] = (ndp[j] + dp[l]) % M;
            dp = ndp;
        }
        int ans = 0;
        for (int x : dp) ans = (ans + x) % M;
        return ans;
    }
};
