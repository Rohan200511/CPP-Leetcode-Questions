class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;

        for(char c : n){
            int bit = c - '0';
            ans = max(ans , bit);
        }
        return ans;
    }
};