class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = groups.size();

        // Always include the first word
        ans.push_back(words[0]);
        int last_group = groups[0];

        // Start from second element
        for(int i = 1; i < n; i++) {
            if(groups[i] != last_group) {
                ans.push_back(words[i]);
                last_group = groups[i]; // Update last_group
            }
        }

        return ans;
    }
};
