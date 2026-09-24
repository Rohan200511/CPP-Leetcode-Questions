class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int maxLen = INT_MIN;
        unordered_set<char>st;
        int left = 0;

        for(int right = 0 ; right < n ; right++){
            
            while(st.count(s[right])){
                st.erase(s[left++]);
            }
            st.insert(s[right]);
            
            maxLen = max(maxLen , right - left + 1);

        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};