class Solution {
public:

    int n;

    vector<vector<int>>t;
    int total;

    int solve(vector<int>& nums , int target , int i , int sum){

        if(i == n && sum != target) return 0;
        if(i == n && sum == target) return 1;

        if(t[i][sum + total] != -1) return t[i][sum + total];

        int plus = solve(nums , target ,  i + 1 , sum + nums[i]);
        int minus = solve(nums , target , i + 1 , sum - nums[i]);

        return t[i][sum + total] =  plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);

        t.assign(n , vector<int>(2 * total + 1 , -1));

        return solve(nums , target , 0 , 0);
    }
};