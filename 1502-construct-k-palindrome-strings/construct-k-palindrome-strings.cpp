class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;

        unordered_map<char , int>mp;

        for(char c : s){
            mp[c]++;
        }

        int count = 0;

        for(auto& it : mp){
            if(it.second % 2 == 1) count++;
        }

        return count <= k;
    }
};