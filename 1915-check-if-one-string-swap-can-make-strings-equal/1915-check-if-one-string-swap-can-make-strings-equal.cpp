class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int n= s1.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) count++;
        }
        if(count==2){
            vector<int>indx;
            for(int i=0; i<s1.size(); i++){
                if(s1[i]!=s2[i]){
                    indx.push_back(i);
                }
            }
            int a1=indx[0];
            int a2=indx[1];
            swap(s1[a1],s1[a2]);
            if(s1==s2){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};