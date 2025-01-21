class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        map< int, int> m,ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                m[matrix[i][j]]++;
                ans[matrix[j][i]]++;
            }
            for(auto a : ans){
                if(a.second>1 ){
                    return false;
                }
            }
            for(auto x : m){
                if(x.second>1){
                    return false;
                }
            }
            for(int j=0;j<col;j++){
                m[matrix[i][j]]=0;
                ans[matrix[j][i]]=0;
            }
        }
        return true;
    }
};