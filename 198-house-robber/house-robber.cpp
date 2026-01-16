class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        

        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 2 ; i <= n ; i++){

            int steal = nums[i-1] + prev2;
            int skip = prev1;

            int temp = max(steal , skip);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};