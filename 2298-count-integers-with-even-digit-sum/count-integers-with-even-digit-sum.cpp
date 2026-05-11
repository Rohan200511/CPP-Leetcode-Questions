class Solution {
public:
    int countEven(int num) {
        int x = num;
        int sum = 0;

        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        if(sum % 2 == 0) return x / 2;
        return (x - 1) / 2;
    }
};