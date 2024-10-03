class Solution {
public:
    int bestClosingTime(string customers) {
    int n = customers.size();
    int pre[n+1];
    int suf[n+1];
    pre[0]= 0;
    for(int i=0;i<n;i++){
        int count =0;
        // if(customers[i]=='N')count++;
        pre[i+1]= pre[i] + ((customers[i]=='N') ? 1:0);
    }
    suf[n]=0;
    for(int i=n-1;i>=0;i--){
        suf[i]= suf[i+1] + ((customers[i]=='Y') ? 1:0);
    }
    int minp = n;

    for(int i=0;i<=n;i++){
        pre[i]+=suf[i];
        int penalty = pre[i];
        minp=min(minp,penalty);
    }
    for(int i=0;i<=n;i++){
        int p = pre[i];
        if(p==minp) return i;
    }
    // or return minp;
    return n;
    }
};