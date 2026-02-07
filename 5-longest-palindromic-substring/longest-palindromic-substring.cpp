class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>>t(n , vector<bool>(n , false));

        int maxL = 1 , idx = 0;
        for(int i = 0; i < n ; i++) t[i][i] = true;

        for(int l = 2 ; l <= n ; l++){
            for(int i = 0 ; i + l - 1 < n ; i++){
                int j = i + l - 1;

                if(s[i] == s[j] && l == 2){
                    t[i][j] = true;
                    maxL = 2;
                    idx = i;
                }

                else if(s[i] == s[j] && t[i+1][j-1] == true){
                    t[i][j] = true;
                    maxL = (maxL < (j-i+1)) ? j-i+1 : maxL;
                    idx = i;
                }
            }
        }
        return s.substr(idx , maxL);
    }
};