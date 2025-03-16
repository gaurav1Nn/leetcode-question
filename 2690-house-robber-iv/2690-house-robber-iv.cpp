class Solution {
public:
    bool checker(vector<int>&nums, int mid,int k){
       int prev=-1;
       int total=0;
       bool first=false;
       for(int i=0; i<nums.size(); i++){
        if(nums[i]<=mid && prev==-1){
            prev=i;
            total++;
            first=true;
            continue;
        }
        if(nums[i]<=mid && first && prev!=i-1){
             total++;
             prev=i;
        }
        
       }
       return (total>=k);
    }
    int minCapability(vector<int>& nums, int k) {
        int start=*min_element(nums.begin(),nums.end());
        int end=*max_element(nums.begin(),nums.end());
        int ans;
        while(start<=end){
            int mid=(start+(end-start)/2);
            if(checker(nums,mid,k)){
                end=mid-1;
                ans=mid;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
