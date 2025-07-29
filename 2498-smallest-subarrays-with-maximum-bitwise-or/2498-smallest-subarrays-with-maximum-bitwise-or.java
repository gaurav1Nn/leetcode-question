class Solution {
    public int[] smallestSubarrays(int[] A) {
        int n = A.length, last[] = new int[30], res[] = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            res[i] = 1;
            for (int j = 0; j < 30; ++j) {
                if ((A[i] & (1 << j)) > 0)
                    last[j] = i;
                res[i] = Math.max(res[i], last[j] - i + 1);
            }
        }
        return res;
    }
};