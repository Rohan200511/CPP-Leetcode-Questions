class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size() , 1);

        for(int i = 1 ; i<nums.size() ; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        int suffix = 1;
        for(int j = nums.size()-2 ; j>=0;j--){
            suffix *= nums[j+1];
            ans[j] *= suffix;
        }
        return ans;
    }
};