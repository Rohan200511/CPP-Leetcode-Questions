class Solution {
  public:   
    
    vector<vector<int>>t;
    
    int solve(int W , vector<int>& val , vector<int>& wt , int n){
        if(W == 0 || n == 0) return 0;
        
        if(t[W][n] != -1) return t[W][n];
        
        int pick = 0;
        
        if(wt[n-1] <= W){
            pick = val[n-1] + solve(W - wt[n-1] , val , wt , n-1);
        }
        
        int not_pick = solve(W , val , wt , n-1);
        
        return t[W][n] = max(pick , not_pick);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        t.assign(W+1 , vector<int>(n+1 , -1));
        return solve(W , val , wt , n);
    }
};