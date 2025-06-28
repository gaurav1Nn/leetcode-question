class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>> ans ;
        for(int i=0;i<n;i++){
             ans.emplace_back(i, nums[i]);
        }
        sort(ans.begin() , ans.end(),
        [&](auto x1 , auto x2){return x1.second > x2.second ;
        });

        sort(ans.begin() , ans.begin() + k);
        vector<int> res;
        for(int i=0 ; i<k;i++){
            res.push_back(ans[i].second);
        }
        return res;
    }
};