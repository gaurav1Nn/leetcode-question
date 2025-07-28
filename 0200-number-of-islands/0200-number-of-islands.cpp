class Solution {
public:
void dfs(vector<vector<char>>& grid , int i , int j){
    int m = grid.size();
    int n = grid[0].size();
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0'){
        return ;
    }
    grid[i][j]= '0'; // ark as visited
    dfs(grid , i+1 , j); // up
    dfs(grid , i-1 , j); // down 
    dfs(grid , i , j+1);// left
    dfs(grid , i , j-1);// right
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count= 0;
        if(n==0) return 0;
        for(int i = 0; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};