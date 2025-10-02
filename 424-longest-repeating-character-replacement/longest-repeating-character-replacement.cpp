class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0 , r = 0;
        int maxLen = 0;
        int freq = 0;
        vector<int>count(26,0);

        while(r < n){
            count[s[r] - 'A']++;
            freq = max(freq , count[s[r] - 'A']);

            if(((r-l+1) - freq) > k){
                count[s[l] - 'A']--;
                l++;
            }
           if((r-l+1) - freq <= k){
                maxLen = max(maxLen , r-l+1);
                r++;
            }
        }
        return maxLen;
    }
};