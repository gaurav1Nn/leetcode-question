class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int index = -1;
        int n = arr.size();

        //step1:
        //find any index (peak) where arr[i]<arr[i+1] and break whenever you get that

            for(int i=n-2; i>=0; i--){
            if(arr[i]<arr[i+1]) {
                index = i;
                break;
            }
        }

        // for the edge case of last element's permutataion
        //if we are unable to find any index such that arr[i]<arr[i+1] this means we are at the last permutation
        //answer will be the very first permutation that would be reverse of last one

        if(index==-1) {
            reverse(arr.begin(),arr.end());
            return;
        }

        // step 2:
        // find out the next greater element at right than arr[index]
        //traversing from right would be beneficial
        // after getting that element swap it with the arr[index]
        for(int i=n-1; i>=0; i--){
            if(arr[i]>arr[index]) {
                swap(arr[index],arr[i]) ;
                break;
            } 
        }
   
        // remaining answer will be decreasingly sorted automatically
        //just reverse or sort 
        
        reverse(arr.begin()+index+1, arr.end());



    }
};