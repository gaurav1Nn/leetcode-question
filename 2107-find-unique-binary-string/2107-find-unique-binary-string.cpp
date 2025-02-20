class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result(n, '0');  
     
        for(int i = 0; i < n; i++) {
           
            result[i] = (nums[i][i] == '0') ? '1' : '0';
        }
        
        return result;
    }
};