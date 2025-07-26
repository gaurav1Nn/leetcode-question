class Solution {

public:
    void dfs(int start , vector<vector<int>>& matrix , vector<bool>& visited , int n){
        visited[start] = true;
        for(int j=0;j<n;j++){
            if(matrix[start][j]==1 && !visited[j]){
                dfs(j , matrix , visited , n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int n = is.size();
        vector<bool> visited(n,false);
        int count = 0 ;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i , is , visited , n);
            }
        }
        return count;
    }
};