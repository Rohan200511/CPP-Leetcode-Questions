class Solution {
private:
    int reverse(int& n){
        int digit = 0;

        while(n != 0){
            digit = digit * 10 + n % 10;
            n /= 10;
        }
        return digit;
    }
public:
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};