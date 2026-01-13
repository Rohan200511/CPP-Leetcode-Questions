class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();

        if(n <= 3) return stones[n-1] - stones[0];

        int ans = 0;

        for(int i = 2 ; i < n ; i++){
            ans = max(ans , stones[i] - stones[i-2]);
        }
        return ans;
    }
};