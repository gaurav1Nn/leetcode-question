class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result;
        int i = 0;

        while (i < n) {

            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i >= n) break; 

            int j = i;
            while (j < n && s[j] != ' ') {
                j++;
            }

            
            string sub = s.substr(i, j - i);

            if (result.empty()) {
                result = sub; 
            } else {
                result = sub + " " + result;
            }
            i = j; 
        }

        return result; 
    }
};