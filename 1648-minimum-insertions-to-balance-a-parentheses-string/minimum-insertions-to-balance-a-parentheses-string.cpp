class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int open = 0;
        int required = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') open++;
            else{
                if(i+1 < n && s[i+1] == s[i]){
                    if(open > 0) open--;
                    else required++;
                    i++;
                }
                else {
                    required++;
                    if(open > 0) open--;
                    else required++;
                }
            }
        }
        return required + open*2;
    }
};