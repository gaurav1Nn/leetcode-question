class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // First sort the intervals based on starting times
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                // No overlap, add interval directly
                ans.push_back(intervals[i]);
            } else {
                // Overlap exists, merge the intervals
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
// intervals = {{1,3}, {2,6}, {8,10}, {15,18}} // already sorted
// tc = o(nlogn)
// space : o(n) ; 