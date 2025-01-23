class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        map<int,int> rowv;
        map<int,int> colv;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) {
                    rowv[i]++;
                    colv[j]++;
                }
            }
        }
        int count =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1) {
                    if(rowv[i]>1 || colv[j]>1)  count++;

                }
            }
        }
        return count;
    }
};