class Solution {
  public:
    
    int n;
    int t[1001][1001];
    int dfs(vector<int>& arr , int target , int i , int curr_sum){
        if(i == n){
            return curr_sum == target;
        }
        
        if(t[i][curr_sum] != -1) return t[i][curr_sum];
        
        int exclude = dfs(arr , target , i + 1 , curr_sum);
        
        int include = 0;
        
        if(arr[i] + curr_sum <= target){
            include = dfs(arr , target , i + 1 , curr_sum + arr[i]);
        }
        
        return t[i][curr_sum] = (include + exclude);
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // code here
        n = arr.size();
        memset(t , -1 , sizeof(t));
        return dfs(arr , target , 0 , 0);
    }
};