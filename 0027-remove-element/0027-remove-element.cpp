class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        // sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};