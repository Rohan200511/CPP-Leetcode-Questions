class Solution {
public:
    bool validDigit(int n, int x) {
        string num = to_string(n);
        
        for(int i = 0 ; i < num.length() ; i++){
            if(i == 0 && num[i] == x + '0') return false;
            else{
                if(num[i] == x + '0') return true;
            }
        }
        return false;
    }
};