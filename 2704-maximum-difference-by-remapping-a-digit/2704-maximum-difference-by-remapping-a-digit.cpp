class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        
        // ----- MAXIMUM: replace first digit (not 9) with 9 -----
        string maxStr = s;
        for (char d : s) {
            if (d != '9') {
                char toReplace = d;
                for (char &c : maxStr) {
                    if (c == toReplace) c = '9';
                }
                break;
            }
        }

        // ----- MINIMUM: replace first digit (not 0) with 0 -----
        string minStr = s;
        for (char d : s) {
            if (d != '0') {
                char toReplace = d;
                for (char &c : minStr) {
                    if (c == toReplace) c = '0';
                }
                break;
            }
        }

        int maxVal = stoi(maxStr);
        int minVal = stoi(minStr);

        return maxVal - minVal;
    }
};
