class Solution {
public:
    bool  ispossible(vector<int>& p , int k , int h) {
        double hours= 0;
        for(int pile : p){
            hours+= ceil((double)pile/k);
        }
        if(hours<=h) return true ;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left   = 1;
        int right = *max_element(piles.begin(),piles.end());
        int result = right ;
        while(left<=right){
            int mid = left  + (right - left) /2;
            if(ispossible(piles,mid,h)){
                result = mid;
                right = mid -1;
            }
            else{
                left = mid +1;
            }
        }
         return result ;
    }
   
};
