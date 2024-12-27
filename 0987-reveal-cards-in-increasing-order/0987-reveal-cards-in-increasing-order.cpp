class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(),deck.end());
        queue<int>q ;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            q.push(i);
        }
        for(int i=0;i<n;i++){
            int idx = q.front();
            q.pop();
            // poping front and pushing it to the back
            q.push(q.front());
            q.pop();
            ans[idx] = deck[i];
        }
        return ans;
    }
};