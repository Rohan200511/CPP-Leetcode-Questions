class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        n = n | (1 << k);
        return n;
    }
};
