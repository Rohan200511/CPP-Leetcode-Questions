class Solution {

  public:
    int n;    
    vector<vector<int>>dp;
    int solve(vector<int>& arr , int half , int i , int curr){
        if(i == n) return curr;
        if(dp[i][curr] != -1) return dp[i][curr];
        
        int include = 0;
        if(curr + arr[i] <= half)
            include = solve(arr , half , i + 1 , curr + arr[i]);
            
        int exclude = solve(arr , half , i + 1 , curr);
        
        return dp[i][curr] = max(include , exclude);
    }
      
    int minDifference(vector<int>& arr) {
        // Your code goes here
        n = arr.size();
        
        int total = accumulate(begin(arr) , end(arr) , 0);
        
        int half = total / 2;
        
        dp.assign(n+1 , vector<int>(half+1 , -1));
        
        int best = solve(arr , half , 0 , 0);
        
        return total - 2 * best;
    }
};
