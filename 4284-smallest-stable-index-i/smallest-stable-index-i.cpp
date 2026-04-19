class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>prefix(n , INT_MIN);
        vector<int>suffix(n , INT_MAX);

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i = 1 ; i < n ; i++) prefix[i] = max(nums[i] , prefix[i-1]);

        for(int i = n-2 ; i >= 0 ; i--) suffix[i] = min(nums[i] , suffix[i+1]);

        int idx = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            int score = prefix[i] - suffix[i];
            if(score <= k) idx = min(idx , i);
        }

        return (idx == INT_MAX) ? -1 : idx;
    }
};