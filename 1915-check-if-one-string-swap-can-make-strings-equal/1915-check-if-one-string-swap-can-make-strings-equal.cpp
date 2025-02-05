class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        string r1 = s1;
        string r2 = s2;
        if(s1==s2) return true;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(r1[i],r1[j]);
                if(r1==r2){
                    return true;
                }
                 r1 = s1;
            }
           

        }
        return false;
    }
};