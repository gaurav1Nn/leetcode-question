class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1" ;
        string str = countAndSay(n-1);

        string ztr = ""; 
        int fre = 1;
        char ch = str[0];
        for(int i=1;i<str.length();i++){
            char dh = str[i];
            if(ch==dh){
                fre++;
            }
            else{
                ztr+=(to_string(fre)+ch);
                ch = dh;
                fre=1;
            }
        }
        ztr+=(to_string(fre)+ch);
        return ztr;
    }
};