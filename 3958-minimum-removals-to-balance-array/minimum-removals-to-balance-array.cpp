class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;

        sort(nums.begin() , nums.end());

        int ans = n;
        int i = 0;

        for(int j = 0 ; j < n ; j++){
            while(i <= j && nums[j] > 1LL * k * nums[i]) i++;
            ans = min(ans , n - (j - i + 1));
        }

        return ans;
    }
};