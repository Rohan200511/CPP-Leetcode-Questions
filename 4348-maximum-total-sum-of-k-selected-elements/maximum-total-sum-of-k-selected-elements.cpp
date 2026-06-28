class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<>());
        
        long long ans=0;
        
        for(int i = 0; i < k; i++){
            if(mul > 1){
                ans += ((long long) mul * nums[i]);
                mul--;
            }
            else ans += nums[i];
        }
        return ans;
    }
};