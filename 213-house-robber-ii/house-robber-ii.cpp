class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        
        int prev2 = 0;
        int prev1 = 0;
        for(int i = 1 ; i <= n-1 ; i++){
            int take = nums[i-1] + ((i-2 >= 0) ? prev2 : 0);
            int skip = prev1;

            int temp = max(take , skip);
            prev2 = prev1;
            prev1 = temp;
        }

        int result1 = prev1;


        prev2 = 0;
        prev1 = 0;

        for(int i = 2 ; i <= n ; i++){
            int take = nums[i-1] + ((i-2 >= 0) ? prev2 : 0);
            int skip = prev1;

            int temp = max(take , skip);
            prev2 = prev1;
            prev1 = temp;
        }

        int result2 = prev1;

        return max(result1 , result2);



    }
};