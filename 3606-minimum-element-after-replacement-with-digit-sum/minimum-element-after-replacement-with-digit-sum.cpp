class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;

        for(int num : nums){
            int sum = 0;

            while(num > 0){
                int digit = num % 10;
                sum += digit;
                num /= 10;
            }

            ans = min(sum , ans);
        }
        return ans;
    }
};