class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int ans = 0 ; 
        int maxa = -1;
        for(int i = n-1 ; i>=0 ; i--){
            maxa = max(maxa , p[i]);
            int x = maxa - p[i];
            ans = max(x , ans);
        }
        return ans;
    }
};