#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq_map;

        // Step 1: Count frequencies
        for (char c : word) {
            freq_map[c]++;
        }

        // Step 2: Extract frequencies
        vector<int> freqs;
        for (auto& pair : freq_map) {
            freqs.push_back(pair.second);
        }

        int max_freq = *max_element(freqs.begin(), freqs.end());
        int min_deletions = INT_MAX;

        // Step 3: Try every possible target frequency f
        for (int f = 1; f <= max_freq; ++f) {
            int deletions = 0;
            for (int freq : freqs) {
                if (freq < f) {
                    deletions += freq;  // delete all
                } else if (freq > f + k) {
                    deletions += freq - (f + k);  // delete extra
                }
                // else: keep as-is
            }
            min_deletions = min(min_deletions, deletions);
        }

        return min_deletions;
    }
};
