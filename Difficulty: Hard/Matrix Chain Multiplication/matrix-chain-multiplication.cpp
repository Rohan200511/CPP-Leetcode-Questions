class Solution {
  public:
  int n;    
  vector<vector<int>>t;
    int solve(vector<int>& arr , int i , int j){
        if(i == j) return 0;
        if(t[i][j] != -1) return t[i][j];
        int ans = INT_MAX;
        
        for(int k = i ; k < j ; k++){
            int cost = solve(arr , i , k) + solve(arr , k + 1 , j) + arr[i-1] * arr[k] * arr[j];
        
            ans = min(ans , cost);
        }
        return t[i][j] = ans;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        n = arr.size();
        t.assign(n , vector<int>(n , -1));
        return solve(arr , 1 , n-1);
    }
};