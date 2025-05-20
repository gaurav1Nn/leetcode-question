class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        int top=0,left=0,right=m-1,bottom=n-1;

        while(top <= bottom && left <= right){
            // For top most Row
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            // For right most col
            for(int i=top;i<=bottom;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            // For bottom part
            if(top <= bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            // For left most part
            if(left <= right){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
            
        }
        return ans;
    }
};