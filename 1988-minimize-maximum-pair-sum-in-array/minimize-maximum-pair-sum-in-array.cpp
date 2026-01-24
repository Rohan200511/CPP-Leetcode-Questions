class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int sum = INT_MIN;

        for(int i = 0 ; i <= nums.size() / 2 ; i++){
            sum = max(sum , (nums[i] + nums[n-i-1]));
        }
        return sum;
    }
};