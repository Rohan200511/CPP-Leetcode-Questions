class Solution {
  public:
  int reverseDigitsHelper(int n, int rev) {
        if (n == 0)
            return rev;
        return reverseDigitsHelper(n / 10, rev * 10 + n % 10);
    }
    int reverseDigits(int n) {
        // Code here
        n = abs(n);
        return reverseDigitsHelper(n,0);
    }
};