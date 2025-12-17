class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int lo = 0 ; 
        int hi = arr.size() - 1;
        
        while(lo < hi){
            int mid = lo + ((hi - lo) / 2);
            
            if(arr[mid] > arr[hi]) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
