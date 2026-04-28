class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>nums;

        for(auto& row : grid){
            for(int val : row){
                nums.push_back(val);
            }
        }

        int rem = nums[0] % x;
        for(int val : nums){
            if(val % x != rem) return -1;
        }

        sort(begin(nums) , end(nums));

        int p = nums.size();

        int median = nums[p / 2];

        int ops = 0;
        for(int val : nums){
            ops += abs(val - median) / x;
        }

        return ops;
    }
};