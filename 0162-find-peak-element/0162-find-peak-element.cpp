class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n= arr.size();
        if(n==0 || n==1) return 0;
        if(arr[0] > arr[1]) return 0; //peak is 0th index
        if(arr[n-1] > arr[n-2]) return n-1; //peak is last index
        int low = 1;
        int high = n-2;
        int mid = 0 ;
        while(low<=high){
            mid = (low+high)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1]){
                low = mid +1;
            }
            else {
                high = mid;
            }
        }
        return -1;
        
    }
};