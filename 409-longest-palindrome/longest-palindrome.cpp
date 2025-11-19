class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }

        int oddNo = 0;

        for(auto& it : mp){
            if(it.second % 2 == 1) oddNo++;
        }

        if(oddNo > 1) return n - oddNo +1;
        return n;
    }
};