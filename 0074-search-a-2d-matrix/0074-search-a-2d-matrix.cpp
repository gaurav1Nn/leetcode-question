class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        if (matrix.empty() || matrix[0].empty()) return false;
            
        int s = 0;
        for(int i = 0; i<r;i++){
            if(matrix[i][0]<=target && matrix[i][c-1]>=target){
                 s = i;
                break;
            }
        }
        if (s == -1) return false; 
        for(int j=0;j<c;j++){
            if(matrix[s][j]==target){
                return true;
            }
        }
        return false;
        //  return binary_search(matrix[s].begin(), matrix[s].end(), target);
    }
};