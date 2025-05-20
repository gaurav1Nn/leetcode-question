class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;

        for (int i = 0; i < s.size(); ++i) {
            unordered_map<char, int> freq;

            for (int j = i; j < s.size(); ++j) {
                freq[s[j]]++;

                int maxFreq = 0, minFreq = INT_MAX;

                for (auto& pair : freq) {
                    maxFreq = max(maxFreq, pair.second);
                    minFreq = min(minFreq, pair.second);
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};
