class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        long long divi=dividend;
        long long dvs=divisor;
        long long quotient=divi/dvs;
        if(quotient>INT_MAX) return INT_MAX;
        if(quotient < INT_MIN) return INT_MIN;
        return static_cast<int>(quotient);
    }
};