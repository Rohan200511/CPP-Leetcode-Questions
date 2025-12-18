class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int avg = (sum + i) / (i + 1); 
            ans = max(ans, avg);
        }
        return ans;
    }
};