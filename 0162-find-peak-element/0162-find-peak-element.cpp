class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n= arr.size();
        if(n==0 || n==1) return 0;
        if(arr[0] > arr[1]) return 0; //peak is 0th index
        if(arr[n-1] > arr[n-2]) return n-1; //peak is last index

        int peaki=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                peaki = i;
                break;
            }
        }
        return peaki;
    }
};