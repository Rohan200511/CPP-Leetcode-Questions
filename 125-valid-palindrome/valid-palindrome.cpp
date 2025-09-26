class Solution {
public:

    bool isPal(string &s , int st , int e){
            if(st >= e) return true;
            if(!isalnum(s[st])) return isPal(s,st+1,e);
            else if(!isalnum(s[e])) return isPal(s,st,e-1);
            else if(tolower(s[st]) != tolower(s[e])) return false;
            return isPal(s,st+1,e-1);
    }

    bool isPalindrome(string s) {
        return  isPal(s,0,s.length()-1);
    }
};