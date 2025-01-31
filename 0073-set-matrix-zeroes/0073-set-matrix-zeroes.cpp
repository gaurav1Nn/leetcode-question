class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int colu = matrix[0].size();
        vector<int> r(row,0);
        vector<int> c(colu,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<colu;j++){
                if(matrix[i][j]==0){
                    r[i]=1;
                    c[j]=1;
                }
            }
        }
         for(int i=0;i<row;i++){
            for(int j=0;j<colu;j++){
                if(r[i]==1 || c[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
        // return matrix;
    }
};