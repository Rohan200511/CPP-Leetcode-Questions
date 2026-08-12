class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 1) return 1;

        unordered_map<int , int>mp;

        int l = 0;
        int ans = INT_MIN;
        
        for(int r = 0 ; r < n ; r++){
            mp[nums[r]]++;

            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans , r - l + 1);
        }
        return ans;
    }
};