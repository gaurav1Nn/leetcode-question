class Solution {
public:

string makeFancyString(string s) {
    string res = "";
    for (char c : s) {
        int n = res.size();
        if (n >= 2 && res[n - 1] == res[n - 2] && res[n - 1] == c) {
            continue; // skip adding the 3rd same character
        }
        res += c;
    }
    return res;
}

};