class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        
        s += s;

        int count1 = 0 , count2 = 0; //010101....  101010...

        int ans = INT_MAX;

        for(int i = 0 ; i < 2 * n ; i++){
            if(i % 2 == 0){
                if(s[i] == '1') count1++;
                else count2++;
            }
            else{
                if(s[i] == '0') count1++;
                else count2++;
            }

            if(i >= n){
                int j = i - n;

                if(j % 2 == 0){
                    if(s[j] == '1') count1--;
                    else count2--;
                }
                else{
                    if(s[j] == '0') count1--;
                    else count2--;
                }
            }

            if(i >= n - 1){
                ans = min(ans, min(count1, count2));
            }
        }
        return ans;
    }
};