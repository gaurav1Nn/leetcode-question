#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(
            maxSum(nums, firstLen, secondLen),
            maxSum(nums, secondLen, firstLen)
        );
    }
    
private:
    // Helper: computes max sum of firstLen subarray before secondLen subarray
    int maxSum(vector<int>& nums, int L, int R) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i+1] = prefix[i] + nums[i];

        int maxL = 0;
        int res = 0;

        // i is the start index of the R-length subarray
        for (int i = L; i <= n - R; ++i) {
            int sumL = prefix[i] - prefix[i - L];
            maxL = max(maxL, sumL);

            int sumR = prefix[i + R] - prefix[i];

            res = max(res, maxL + sumR);
        }

        return res;
    }
};
