class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > n) return "";

        int i = 0;
        int j = 0;
        int minWindowsize = INT_MAX;
        int countReqd = t.length();

        unordered_map<char,int>mp;
        for(auto it : t){
            mp[it]++;
        }

        int start_i = 0;

        while(j < n){
            if(mp[s[j]] > 0){
                countReqd--;
            }
            mp[s[j]]--;

            while(countReqd == 0){

                if(minWindowsize > j-i+1){
                    minWindowsize = j-i+1;
                    start_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) countReqd++;
                i++;
            }
            j++;
        }
        return (minWindowsize == INT_MAX) ? "" : s.substr(start_i , minWindowsize);
    }
};