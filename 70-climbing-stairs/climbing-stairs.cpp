class Solution {
public:
    int t[46];
    Solution(){
        memset(t , -1 , sizeof(t));
    }

    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(t[n] != -1) return t[n];

        return t[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};