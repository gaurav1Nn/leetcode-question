class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;  // minimum possible open '(' brackets
        int maxOpen = 0;  // maximum possible open '(' brackets

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--;     // treat '*' as ')'
                maxOpen++;     // treat '*' as '('
            }

            if (maxOpen < 0) return false; // too many ')'
            if (minOpen < 0) minOpen = 0;  // can't have negative open brackets
        }

        return minOpen == 0;
    }
};
