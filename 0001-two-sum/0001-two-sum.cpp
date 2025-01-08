class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> map; // for integer and index
        for(int i=0;i<n;i++){
            int x = target- nums[i];
            if(map.find(x)!=map.end()){
                ans.push_back(map[x]);
                ans.push_back(i);
            }
            else{
                map[nums[i]] = i;
            }
        }
        return ans;
    }
};