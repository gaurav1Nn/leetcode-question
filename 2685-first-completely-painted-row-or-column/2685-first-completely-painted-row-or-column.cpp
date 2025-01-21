class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows=mat.size();
        int col=mat[0].size();
        map<int,int>mpr;
        map<int,int>mpcol;
        map<int,pair<int,int>>mpmat;
        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                mpmat[mat[i][j]]={i,j};
            }
        }
        int ans=0;
        for(int i=0; i<arr.size(); i++){
            int r=mpmat[arr[i]].first;
            int c=mpmat[arr[i]].second;
            mpr[r]++;
            mpcol[c]++;
            if(mpr[r]==col || mpcol[c]>=rows){
                ans=i;
                break;
            }

        }
        return ans;


    }
};