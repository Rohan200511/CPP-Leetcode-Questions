class Solution {
  public:
  
    int helper(vector<int>& arr, int n){
        if(n==0) return 0;
        int maxi = arr[n-1];
        return max(maxi , helper(arr,n-1));
    }
    int largest(vector<int> &arr) {
        // code here
        int n = arr.size();
        return helper(arr,n);
    }
};
