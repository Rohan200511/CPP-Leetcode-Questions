class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>mp;
        mp[0] = 1;

        int count = 0;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            count += nums[i] % 2;

            int left = count - k;

            if(mp.find(left) != mp.end()) ans += mp[left];

            mp[count]++;
        }
        return ans;
    }
};