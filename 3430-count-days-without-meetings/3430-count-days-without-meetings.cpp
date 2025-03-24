class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        int count=0;
       sort(m.begin(),m.end());
       int preve=0;

       for(auto& meet:m){
        int start=meet[0];
        int end=meet[1];

        if(start>preve+1){
           count+=(start-preve-1);
        }
        preve=max(preve,end);
       }
       if(preve<days){
        count+=days-preve;
       }
        
        return count;
    }
};