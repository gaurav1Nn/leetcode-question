class Solution {
public:
    vector<int> greaterElements(vector<int> nums2){
        vector<int> ans(nums2.size());
        stack<int> s;
        s.push(-1);

        for(int i = nums2.size() - 1; i >= 0; i--){
            while(s.top() != -1 && nums2[i] > s.top()){
                s.pop();
            }
            ans[i] = s.top();
            s.push(nums2[i]);
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreaterElementArr(nums2.size());
        vector<int> result;
        nextGreaterElementArr = greaterElements(nums2);

        for(int i = 0; i < nums1.size(); i++){
            auto it = find(nums2.begin() , nums2.end() , nums1[i]);

            if( it != nums2.end() ){
                result.push_back(nextGreaterElementArr[it - nums2.begin()]);
            }

        }

        return result;
    }
};