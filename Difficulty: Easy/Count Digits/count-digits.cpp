class Solution {
  public:
    int countDigits(int n) {
        // code here
         int c=0;
        while(n!=0){
            c++;
            n/=10;
        }
        return c;
    }
};