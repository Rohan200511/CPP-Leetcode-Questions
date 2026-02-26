class Solution {
public:
    int findComplement(int num) {
        string bits;

        while(num > 0){
            if((num & 1) == 1) bits += '0';
            else bits += '1';
            num >>= 1;
        }
        int decimal = 0;

        for(int i = bits.length() - 1 ; i >= 0 ; i--){
            decimal = decimal * 2 + bits[i] - '0';
        }
        return decimal;
    }
};