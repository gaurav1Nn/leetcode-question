class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }else{
                nums[i]=1;
            }
        }
        int n=nums.size();
        int sum=0;
        int count=0;
        hash[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            count+=hash[sum-k];
            hash[sum]++;
        }
        return count;
    }
};