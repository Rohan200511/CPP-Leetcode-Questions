class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string sub = doubled.substr(1 , doubled.length()-2);
        if(sub.find(s) != string::npos) return true;
        return false;
    }
};