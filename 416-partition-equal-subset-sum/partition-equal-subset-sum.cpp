class Solution {
public:

    int n;

    vector<vector<int>>dp;
    
    int solve(vector<int>& arr , int sum , int i){
        if(sum == 0) return 1;
        if(i >= n) return sum == 0;
        if(sum < 0) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        int skip = solve(arr , sum , i + 1);
        int take = 0;
        
        if(arr[i] <= sum){
            take = solve(arr , sum - arr[i] , i + 1);
        }
        
        return dp[i][sum] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        dp.assign(n , vector<int>(target + 1 , -1));
        return solve(nums , target , 0);
    }
};