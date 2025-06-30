class Solution {
public:
    int removeElement(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans ;
        for(int i = 0 ; i <n ; i++){
            if(nums[i]!=k){
                ans.push_back(nums[i]);
            }
        }
        int e  = ans.size();
        nums = ans ;
        return e;
    }
};