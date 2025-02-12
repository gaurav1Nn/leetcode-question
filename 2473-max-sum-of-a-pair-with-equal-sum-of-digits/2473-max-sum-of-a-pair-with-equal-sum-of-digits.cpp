class Solution {
private:
    int dSum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int maximumSum(vector<int>& nums) {
        vector<priority_queue<int, vector<int>, greater<int>>> g(82);
        int maxSum = -1;

        for (int n : nums) {
            int s = dSum(n);
            g[s].push(n);
            if (g[s].size() > 2) {
                g[s].pop();
            }
        }
        for (auto& h : g) {
            if (h.size() == 2) {
                int f = h.top();
                h.pop();
                int sec = h.top();
                maxSum = max(maxSum, f + sec);
            }
        }

        return maxSum;
    }
};