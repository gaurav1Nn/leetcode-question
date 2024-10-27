class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive ;
        vector<int> negative;
        
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                negative.push_back(nums[i]);
            }
            else{
                positive.push_back(nums[i]);
            }
        }
        vector<int> final;
        for(int i=0;i<n;i++){
            if(positive[i/2]!=0 || negative[i/2]!=0){
                if(i%2==0){
                    final.push_back(positive[i/2]);
                }
                else{
                    final.push_back(negative[i/2]);
                }
            }
        }
        return final;
    }
};