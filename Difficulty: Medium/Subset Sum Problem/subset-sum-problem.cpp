class Solution {
  public:   
    
    bool recurse(vector<int>& arr , int sum , vector<vector<int>>& memo , int n){
        if(sum == 0) return 1;
        
        if(n <= 0) return 0;
        
        if(memo[n][sum] != -1) return memo[n][sum];
        
        if(arr[n-1] > sum) return memo[n][sum] = recurse(arr , sum , memo, n-1);
        
        else return memo[n][sum] = recurse(arr,sum,memo,n-1) || recurse(arr,sum-arr[n-1],memo,n-1);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        
        vector<vector<int>>memo(n+1 , vector<int>(sum+1 , -1));
        
        return recurse(arr , sum , memo , n);
    }
};