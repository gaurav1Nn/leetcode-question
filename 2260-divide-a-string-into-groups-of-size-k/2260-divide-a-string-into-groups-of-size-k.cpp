class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n= s.size();
        int x = n%k;
        int y = n - x;
        vector<string>  ans;
        for(int i=0;i<y;i+=k){
            string f = "";
            for(int e = 0; e<k;e++){
                f+= s[i+e];
            }
            ans.push_back(f);
        }
        if(x==0) return ans;
        string z = "";
        for(int i=y;i<n;i++){
            z+=s[i];
        }
        int b = k - z.size();
        for(int i=0;i<b;i++){
            z += fill;
        }
        ans.push_back(z);
        return ans;
    }
};