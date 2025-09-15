class Solution {
  public:
    
    int helper(vector<int>& arr , int k,int low,int high){
       if (low > high)
            return -1;
        int mid = (low + high) / 2;
        
        if(arr[mid] == k){
            if(mid == 0 || arr[mid-1]!=k) return mid;
            else
                return helper(arr, k, low, mid - 1);
        }
        
        if(arr[mid] < k) return helper(arr,k,mid+1,high);
        else return helper(arr,k,low,mid-1);
    }
    
    int binarysearch(vector<int> &arr, int k) {
        // code here
       return helper(arr,k,0,arr.size()-1);
    }
};