class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> ans;
        vector<int> e;
        for(int i=0;i<arr.size();i++){
            ans[arr[i]]++;
        }
        for(auto x : ans){
            if(x.first == x.second){
                e.push_back(x.first);
            }
        }
        int a = e.size();
        sort(e.begin(),e.end());
        if(a==0) return -1;
        return e[a-1];
    }
};