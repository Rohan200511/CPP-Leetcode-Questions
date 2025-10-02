class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n != m) return false;

        unordered_map<char,char> mp , Rmp;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(s[i]) != mp.end()){  
                char ch = mp[s[i]];
                if(t[i] != ch) return false;                 
            }
            else if(Rmp.find(t[i]) != Rmp.end()){  
                char c = Rmp[t[i]];
                if(s[i] != c) return false;  
            }

            else{ 
                mp.insert({s[i] , t[i]});
                Rmp.insert({t[i] , s[i]});
            }
        }
        return true;
    }
};