class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int smallest = INT_MAX , secondSmallest = INT_MAX;

        for (int i = 1; i < n; i++) {
            if (nums[i] < smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            } 
            else if (nums[i] < secondSmallest) {
                secondSmallest = nums[i];
            }
        }
        
        int cost = nums[0] + smallest + secondSmallest;
        return cost;
    }
};