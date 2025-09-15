class Solution {
  public:
  
    bool helper(vector<int>& arr , int n){
        if(n == 0 || n ==1) return true;
        return arr[n-1] >= arr[n-2] && helper(arr,n-1);
    }
    
    bool isSorted(vector<int>& arr) {
        // code here
        int n = arr.size();
        return helper(arr , n);
    }
};