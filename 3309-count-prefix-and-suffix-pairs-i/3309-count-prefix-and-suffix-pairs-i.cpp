class Solution {
public:
    bool istrue(string str1 , string str2){
        int n = str1.size();
        int a = str2.size();
        if(n>a) return false;
        bool flag= false;
        // checking prefix
        for(int i=0;i<n;i++){
            if(str1[i]!=str2[i]) {
                return false;
            }
            else flag = true;
        }
        for(int i=0;i<n;i++){
            if(str1[i]!=str2[a-n+i]) {
                return false;
            }
            else flag = true;
        }
        return flag;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(istrue(words[i],words[j])){
                    count++;
                }
            }
        }
        return count ;
    }
};