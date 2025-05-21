class Solution {
public:
    void dozero(vector<vector<int>>& matrix ,int  i ,int  j){
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int a =0;a<rows; a++){
            matrix[a][j]=0;
        }
        for(int b =0;b<columns; b++){
            matrix[i][b]=0;
        }

    }
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        vector<int> v;
        int columns = matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]==0){
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        for(int i=0;i<v.size();i+=2){
            dozero(matrix , v[i],v[i+1]);
        }
    }
};