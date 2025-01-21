class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,int> mapr;
        map<int,int> mapc;
        int rows = mat.size();
        int col = mat[0].size();
        map<int,pair<int,int>> matp;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                matp[mat[i][j]] = {i,j};
            }
        }
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            int r = matp[arr[i]].first;
            int c = matp[arr[i]].second;
            mapr[r]++;
            mapc[c]++;
            if(mapr[r]==col || mapc[c]==rows){
                ans = i;
                return ans;
            }
        }
        return ans;
    }
};