class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxw = 0;
        int n = height.size();
        int lp = 0 , rp = n - 1;
        while(lp < rp){
            int w = rp-lp ;
            int ht = min(height[lp] ,height[rp] );
            int curr = w*ht;
            maxw = max(curr,maxw);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxw;
    }
};