class Solution {
public:
    std::string longestPalindrome(std::string s) {
        // Check if the input string is empty, return an empty string if so
        if (s.empty())
            return "";

        // Initialize variables to store the indices of the longest palindrome found
        std::vector<int> longestPalindromeIndices = {0, 0};

        for (int i = 0; i < s.length(); ++i) {
            // Find the indices of the longest palindrome centered at character i
            std::vector<int> currentIndices = expandAroundCenter(s, i, i);

            // Compare the length of the current palindrome with the longest found so far
            if (currentIndices[1] - currentIndices[0] > longestPalindromeIndices[1] - longestPalindromeIndices[0]) {
                longestPalindromeIndices = currentIndices;
            }

            // Check if there is a possibility of an even-length palindrome centered at
            // character i and i+1
            if (i + 1 < s.length() && s[i] == s[i + 1]) {
                // Find the indices of the longest even-length palindrome centered at characters
                // i and i+1
                std::vector<int> evenIndices = expandAroundCenter(s, i, i + 1);

                // Compare the length of the even-length palindrome with the longest found so far
                if (evenIndices[1] - evenIndices[0] > longestPalindromeIndices[1] - longestPalindromeIndices[0]) {
                    longestPalindromeIndices = evenIndices;
                }
            }
        }

        // Extract and return the longest palindrome substring using the indices
        return s.substr(longestPalindromeIndices[0], longestPalindromeIndices[1] - longestPalindromeIndices[0] + 1);
    }

private:
    // Helper function to find and return the indices of the longest palindrome
    // extended from s[i..j] (inclusive) by expanding around the center
    std::vector<int> expandAroundCenter(const std::string &s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            --i;
            ++j;
        }
        return {i + 1, j - 1};
    }
};