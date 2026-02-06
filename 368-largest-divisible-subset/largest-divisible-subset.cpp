class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int>dp(n , 1);
        vector<int>prev(n , -1);
        int maxL = 1;
        int last_index = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[i] + 1;
                        prev[i] = j;
                    }
                }

                if(maxL < dp[i]){
                    maxL = dp[i];
                    last_index = i;
                }
            }
        }

        vector<int>ans;

        while(last_index != -1){
            ans.push_back(nums[last_index]);
            last_index = prev[last_index];
        }

        return ans;
    }
};