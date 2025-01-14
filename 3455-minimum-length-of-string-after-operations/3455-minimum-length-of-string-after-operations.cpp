class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> Map;
        for (char current : s) {
            Map[current]++;
        }
        int count  = 0;
        for(auto i : Map){
            int f = i.second;
            if(f%2!=0) count++;
            if(f%2==0) count+=2;
        }
        return count ;
    }
};