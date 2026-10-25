class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        long long ans = 0;

        int left = 0;

        for(int right = 0 ; right < n ; right++){
            if(nums[right] >= minK && nums[right] <= maxK) ans += right - left + 1;

            else left = right + 1;
        }
        return ans;
    }
};