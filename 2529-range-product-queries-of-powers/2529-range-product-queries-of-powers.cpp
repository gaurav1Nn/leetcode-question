class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modInverse(long long a) {
        long long res = 1, p = MOD - 2; // Fermat's Little Theorem
        while (p > 0) {
            if (p & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            p >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // Step 1: Build powers array from binary representation of n
        vector<long long> powers;
        for (int i = 0; i < 31; i++) {
            if ((n >> i) & 1) {
                powers.push_back(1LL << i);
            }
        }

        // Step 2: Build prefix product array
        vector<long long> prefix(powers.size());
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < (int)powers.size(); i++) {
            prefix[i] = (prefix[i-1] * powers[i]) % MOD;
        }

        // Step 3: Answer each query
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            if (l == 0) {
                ans.push_back(prefix[r]);
            } else {
                long long val = (prefix[r] * modInverse(prefix[l-1])) % MOD;
                ans.push_back((int)val);
            }
        }
        return ans;
    }
};
