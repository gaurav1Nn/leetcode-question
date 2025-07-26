class Solution {
public:
    void dfs(int start , vector<vector<int>>& adj , vector<bool>& visited , int n){
        visited[start] = true;
        for(int ne: adj[start] ){
            if(!visited[ne]){
                dfs(ne , adj , visited , n);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& is) {
        int n = is.size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && is[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n,false);
        int count = 0 ;
        for(int i=0; i< n;i++){
            if(!visited[i]){
                count++;
                dfs(i , adj , visited , n);
            }
        }
        return count;
    }
};