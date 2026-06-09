class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++){
            mini = min(mini , nums[i]);
            maxi = max(maxi , nums[i]);
        }

        return (long long)(maxi - mini) * k;
    }
};