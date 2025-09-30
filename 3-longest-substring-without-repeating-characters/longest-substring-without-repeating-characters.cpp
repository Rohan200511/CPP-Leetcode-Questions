class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxStr = INT_MIN;
        set<int>st;
        if(n==0) return 0;
        int l = 0;

        for(int r = 0; r < n ; r++){
            if(st.find(s[r]) != st.end()){
                while(l < r && st.find(s[r]) != st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            maxStr = max(maxStr , r-l+1);
        }
        return maxStr;
    }
};