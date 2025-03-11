class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int left = 0, right = 0;
        // Track frequency of a, b, c
        vector<int> freq(3, 0);
        int total = 0;

        while (right < len) {
            // Add character at right pointer to frequency array
            char curr = s[right];
            freq[curr - 'a']++;

            // While we have all required characters
            while (hasAllChars(freq)) {
                // All substrings from current window to end are valid
                // Add count of these substrings to result
                total += len - right;

                // Remove leftmost character and move left pointer
                char leftChar = s[left];
                freq[leftChar - 'a']--;
                left++;
            }

            right++;
        }

        return total;
    }

private:
    bool hasAllChars(vector<int>& freq) {
        // Check if we have at least one of each character
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }
};