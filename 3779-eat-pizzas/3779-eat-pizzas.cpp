class Solution {
public:
       long long maxWeight(vector<int>& A) {
        int n = A.size(), m = n / 4, z = (m + 1) / 2, y = m / 2;
        sort(A.rbegin(), A.rend());
        long long res = 0;
        int j = 0;
        for (int i = 0; i < z; ++i) {
            res += A[j];
            j += 1;
        }
        for (int i = 0; i < y; ++i) {
            res += A[j + 1];
            j += 2;
        }
        return res;
    }
};