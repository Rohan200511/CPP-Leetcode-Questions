class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;

        for(int num : nums) maxi = max(num , maxi);

        int ans = 0;

        for(int num : nums) ans += maxi - num;

        return ans;
    }
};