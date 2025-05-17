class Solution {
public:
    void solve(int index, vector<int>& c, int target, vector<int>& v, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(v);
            return;
        }

        for (int i = index; i < c.size(); ++i) {
            if (i > index && c[i] == c[i - 1]) continue; // Skip duplicates

            if (c[i] > target) break; // No need to proceed further

            v.push_back(c[i]);
            solve(i + 1, c, target - c[i], v, result); // Move to next index
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> v;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        solve(0, candidates, target, v, result);
        return result;
    }
};
