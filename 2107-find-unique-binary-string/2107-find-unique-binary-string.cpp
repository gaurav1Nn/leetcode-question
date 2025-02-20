class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int>seen;
        for(auto s:nums){
            seen.insert(stoi(s,0,2));
        }
        for(int i=0;i<=n;i++){
            if(seen.find(i)==seen.end()){ // it means i is not present in the set
                string ans = bitset<16>(i).to_string();
                return ans.substr(16-n);
            }
        }
        return "";
    }
};