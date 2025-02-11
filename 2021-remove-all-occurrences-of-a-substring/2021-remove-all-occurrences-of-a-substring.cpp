class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        for(char c : s) {
            result += c;
            if(result.length() >= part.length() && 
               result.substr(result.length()-part.length()) == part) {
                result.erase(result.length()-part.length());
            }
        }
        return result;
    }
};