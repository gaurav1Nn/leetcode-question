// making a vector to store all the values related to it
const string HEX="0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if(num==0)return "0";
        string ans;
        int count=0;
        while(num && count++ < 8){
            ans=HEX[(num & 0xf)] + ans;
            num>>=4; // this is basically like dividing by 16 shifting 4 bits right
        }
        return ans;
    }
};