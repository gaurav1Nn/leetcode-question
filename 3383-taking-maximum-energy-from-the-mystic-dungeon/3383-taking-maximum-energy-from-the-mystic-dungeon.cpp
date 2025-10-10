class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        int n = e.size();
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                e[i] += e[i + k];
            }
        }
        return *max_element(e.begin(), e.end());
    }
};
