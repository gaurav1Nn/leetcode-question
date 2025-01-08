class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0) return 0;
            int count = 1;
            int max_count = 1;
            for(int i=1;i<nums.size();i++){
                if( nums[i]==nums[i-1]) {
                    continue;
                    
                }
                else if(nums[i]-nums[i-1]==1){
                    count++;
                    max_count=max(count,max_count);
                }
                else count =1 ;
            }
        
        return max_count;
    }
};