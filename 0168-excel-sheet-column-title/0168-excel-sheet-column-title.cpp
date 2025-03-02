class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber) {
            columnNumber--;
            char c = 'A' + columnNumber % 26;
            result = c + result;
            columnNumber /= 26;
        }
        return result;
    }
};