class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        int ones = 0 , zeros = 0;

        for(char& c : s){
            if(c == '1') ones++;
        }

        zeros = n - ones;

        int cost = min(ones , zeros);

        cost = min(cost , abs(ones - 1));

        if(n > 1){
            int ans = 0;

            if(s[0] == '0') ans++;
            if(s[n - 1] == '0') ans++;

            for(int i = 1 ; i < n - 1 ; i++){
                if(s[i] == '1') ans++;
            }

            cost = min(ans , cost);
        }

        return cost;
    }
};