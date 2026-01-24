class Solution {
public:
    int minOperations(string s) {
        int op = 0;  
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'a') continue;

            else op = max(op , (26 - (s[i] - 'a') % 26));
        }
        return op;
    }
};