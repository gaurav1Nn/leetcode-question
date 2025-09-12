class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m  = mat[0].size();
        int count1 = 0 ; 
        int maxr = 0;
        int max1 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count1+=mat[i][j];
            }
            if(count1>max1){
                maxr = i;
                max1 = max(count1,max1);
            }
            count1 = 0 ;
        }
        vector<int> ans;
         
        ans.push_back(maxr);
        ans.push_back(max1);
        return ans;
    }
};