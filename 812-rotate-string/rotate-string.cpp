class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int n = max(s.length(),goal.length());
        for(int i=0;i<n;i++){
            s=s.substr(1) + s[0];
            if(s==goal) return true;
        }
        return false;
    }
};