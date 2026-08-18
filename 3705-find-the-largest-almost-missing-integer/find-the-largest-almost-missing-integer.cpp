class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>mp;

        for(int num : nums){
            mp[num]++;
        }

        if(k == 1){
            int ans = INT_MIN;
            for (auto& [num, freq] : mp) {
                if (freq == 1) {
                    ans = max(ans, num);
                }
            }

            return ans == INT_MIN ? -1 : ans;
        }

        else if(k == n){
            return *max_element(nums.begin() , nums.end());
        }

        if (mp[nums[0]] == 1 && mp[nums[n - 1]] == 1) {
            return max(nums[0], nums[n - 1]);
        }
        if (mp[nums[0]] == 1) {
            return nums[0];
        }
        if (mp[nums[n - 1]] == 1) {
            return nums[n - 1];
        }

        return -1;
    }
};