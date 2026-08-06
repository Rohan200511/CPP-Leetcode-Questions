class Solution {
public:

    int productDigit(int x){
        int prod = 1;

        while(x > 0){
            int digit = x % 10;
            prod *= digit;

            x /= 10;
        }

        return prod;
    }

    int smallestNumber(int n, int t) {
        while(true){
            int num = productDigit(n);
            if(num == 0 || num % t == 0){
                return n;
            }
            n++;
        }

        return 0;
    }
};