class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, f = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long long)i * nums[i];
        }

        long long result = f; 

        for (int k = 1; k < n; k++) {
            f = f + sum - (long long)n * nums[n - k];
            result = max(result, f);
        }

        return (int)result;
    }
};