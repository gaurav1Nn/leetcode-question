class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int result = 0;
        bool hasMiddle = false;

        for (string word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (freq[rev] > 0) {
                result += 4;  // one word + its reverse = 4 characters
                freq[rev]--;
            } else {
                freq[word]++;
            }
        }

        // check for a word like "aa", "bb", etc. that can go in the middle
        for (auto& it : freq) {
            if (it.first[0] == it.first[1] && it.second > 0) {
                result += 2; // add one such word in the center
                break;
            }
        }

        return result;
    }
};
