class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;

        for(int num : nums) mini = min(mini , num);

        int moves = 0;

        for(int num : nums){
            moves += num - mini;
        }

        return moves;
    }
};