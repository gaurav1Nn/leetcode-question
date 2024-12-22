class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int mine = INT_MAX;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[low]<=arr[mid]){ // = useful for arr containing only 2 elements
                mine = min(arr[low],mine);
                low = mid+1; // eliminate left half
            }
                // o(logn) solution
            else{
                mine = min(mine,arr[mid]);
                high = mid -1; //eliminate right half
            }
        }
        return mine;
    }
};
