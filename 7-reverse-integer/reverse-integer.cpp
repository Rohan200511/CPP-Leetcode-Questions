class Solution {
public:
    int reverse(int x) {
        int dig;
        int sum=0;
        while(x!=0){
            dig=x%10;
            x/=10;
            if((sum>INT_MAX/10) || (sum<INT_MIN/10)){
            return 0;
        }
            sum = sum * 10 + dig;

        }
        return sum;
    }
};