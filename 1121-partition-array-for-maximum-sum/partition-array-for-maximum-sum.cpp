class Solution {
public:

    int n;

    vector<int>dp;

    int solve(vector<int>& arr , int i , int k){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int curr_max = -1;
        int sum = 0;

        for(int j = i ; j < n && j - i + 1 <= k ; j++){
            curr_max = max(curr_max , arr[j]);
            sum = max(sum , (curr_max * (j - i + 1)) + solve(arr , j + 1 , k));
        }
        return dp[i] = sum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n , -1);
        return solve(arr , 0 , k);
    }
};