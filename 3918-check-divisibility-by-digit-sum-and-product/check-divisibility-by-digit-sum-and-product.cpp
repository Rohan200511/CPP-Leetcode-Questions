class Solution {
public:
    bool checkDivisibility(int n) {
        
        auto sum_prod = [](int temp){
            int s = 0;
            int p = 1;
            while(temp > 0){
                s += temp % 10;
                p *= temp % 10;
                temp /= 10;
            }
            return s + p;
        };

        if(n % sum_prod(n) == 0) return true;
        return false;
    }
};