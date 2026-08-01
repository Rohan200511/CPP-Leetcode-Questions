class Solution {
public:
    bool solve(vector<int>& nums, int i, int j, int p1, int p2, bool turn) {
        if (i > j)
            return p1 >= p2;

        if (turn) { 
            return solve(nums, i + 1, j, p1 + nums[i], p2, false) ||
                   solve(nums, i, j - 1, p1 + nums[j], p2, false);
        } 
        
        else { 
            return solve(nums, i + 1, j, p1, p2 + nums[i], true) &&
                   solve(nums, i, j - 1, p1, p2 + nums[j], true);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1, 0, 0, true);
    }
};