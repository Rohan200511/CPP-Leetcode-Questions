class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int med = nums[n / 2];

        int ans = 0;

        for(int x : nums){
            ans += abs(x - med);
        }

        return ans;
    }
};