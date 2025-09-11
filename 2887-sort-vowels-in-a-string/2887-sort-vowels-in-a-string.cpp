class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
        ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')return true;

        return false;
    }
    string sortVowels(string s) {
        int freq[128]={0};

        for(int i=0;i<s.size();i++){
            if(isVowel(s[i]))freq[(int)s[i]]++;
        }

        int idx=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                while(freq[idx]==0)idx++;
                s[i]=(char)idx;
                freq[idx]--;
            }
        }

        return s;
    }
};