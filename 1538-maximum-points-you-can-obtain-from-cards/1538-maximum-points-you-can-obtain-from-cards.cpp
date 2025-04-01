class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int lsum = 0;
        for(int i=0;i<k;i++){
            lsum = lsum + card[i];
        }
        int rsum = 0;
        // rsum = lsum;
        int max_score = lsum;
        for(int i=0;i<k;i++){
            lsum = lsum - card[k-i-1];
            rsum = rsum + card[n-i-1];
            max_score = max(max_score,lsum+rsum);
        }
        return max_score;

    }
};