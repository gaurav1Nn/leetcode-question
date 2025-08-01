class Solution {
public:
    bool dfs(vector<vector<char>>& board , string word , int i , int j , int idx){
        int m = board.size();
        int n = board[0].size();
        if(idx==word.size()){
            return true;
        }
        if(i>=m || j >= n || i<0 || j<0  )return false;
        if(board[i][j]!=word[idx]) return false;
         if(board[i][j]!=word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#'; // Mark as visited
       
        bool found =dfs(board, word, i+1, j, idx+1) || // down
                     dfs(board, word, i-1, j, idx+1) || // up
                     dfs(board, word, i, j+1, idx+1) || // right
                     dfs(board, word, i, j-1, idx+1);   // left
        board[i][j] = temp;
        return found;          
    };
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,i,j,0))return true;
                
            }
        }
        return false;
    }
};