class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        if(b==0) return a;
        if(a==0) return b;
        if(a==b) return a;
        
        if(b > a) return gcd(b%a , a);
        return gcd(b,a%b);
    }
};
