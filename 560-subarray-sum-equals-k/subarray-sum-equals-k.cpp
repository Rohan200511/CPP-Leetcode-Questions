class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int>mp;

        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            sum += nums[i];

            int reqd = sum - k;

            if(mp.find(reqd) != mp.end()){
                ans += mp[reqd];
            }
            mp[sum]++;
        }

        return ans;
    }
};